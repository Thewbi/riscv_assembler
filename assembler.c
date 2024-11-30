// https://michaeljclark.github.io/asm.html
//
// assemble for testing here: https://riscvasm.lucasteske.dev/#
//
// 1. Parse all lines into asm_line objects. For each instruction, store the amount of bytes it will take so that
//    the label addresses can be computed correctly. All instructions take up 4 byte (32 bit) except for
//    pseudo instructions which are resolved to more than 4 byte (mostly 8 byte)
//    Do not resolve pseudo instructions just yet because labels and symbols are not replaced by concrete values
// 2. Build a map from labels and symbols to addresses or values
// 3. Replace all labels and symbols by numeric values (address or values) in each asm_line
//    For addresses, remember that not each line is 4 byte long but use the length stored in each asm_line instead of just 4
// 4. Replace all pseudo instructions by real instruction asm_line objects
// 5. Encode asm_line objects into 32 bit machine code

#include <stdio.h>
#include <stddef.h>

#include <asm_line.h>
#include <encoder.h>
#include <parser.h>
#include <node.h>
#include <trivial_map/trivial_map.h>
#include <tuple_set/tuple_set.h>

#include "assembler.h"

asm_line_t parser_asm_line;

extern FILE* yyin;
extern int yy_flex_debug;
extern int yydebug;

#define FACTOR 1

// https://www.geeksforgeeks.org/function-pointer-in-c/
//
// fp_emit() which stands for function pointer emit() is provided
// by the encoder. The parser will parse mnemonics from the .s file,
// write data into the parser_asm_line variable that the driver
// provides and it will then call fp_emit() to pass the parser_asm_line
// variable to the module that provided fp_emit().
//
// In the case of this application, the encoder is the module that provides
// fp_emit(). The encoder will encode the parser_asm_line variable to
// machine code and print the machine code to the console.
extern void (*fp_emit)(asm_line_t*);

extern int asm_line_array_index;
extern asm_line_t asm_line_array[100];

// loads equ constants into memory
int mem_preload_value(std::map<uint32_t, uint32_t*>* segments,
    trivial_map_element_t* equ_map, asm_line_t* asm_line,
    uint32_t& constants_address, uint32_t value, bool replace_address) {

    // DEBUG
    printf("address: 0x%08x\n", constants_address);

    uint32_t segment_address = constants_address & 0xFFFF0000;
    uint32_t instr_address = constants_address & 0x0000FFFF;

    uint32_t* segment_ptr = NULL;

    // check if the segment is created already otherwise create it
    std::map<uint32_t, uint32_t *>::iterator it = segments->find(segment_address);
    if (it == segments->end()) {

        segment_ptr = new uint32_t[16384];
        memset(segment_ptr, 0, 16384);

        segments->insert(std::pair<uint32_t, uint32_t*>(segment_address, segment_ptr));

    } else {

        segment_ptr = (*it).second;

    }

    segment_ptr[instr_address] = value;

    //printf("[STORE_WORD] value: %d -> address: 0x%08x\n", cpu->reg[asm_line_array[i].asm_instruction_expr->int_val], constants_address);

    if (replace_address) {
        if (!insert_or_replace_trivial_map(equ_map, 20,
                asm_line->label,
                constants_address)) {
            printf("Insert .equ failed!\n");
            return -1;
        }
    }

    constants_address += 4;

    return 0;
}

uint32_t determine_instruction_size(asm_line_t* data, int label_exists_in_file) {

    if (data->instruction == I_UNDEFINED_INSTRUCTION) {
        return 0;
    }

    switch (data->instruction) {

        case I_CALL:
            // HEURISTIC: if the label exists within the same file, create a simple JAL instead of a auipc and jalr
            if (label_exists_in_file) {
                // resolved into jal
                return 4;
            }
            // resolved into combination of auipc and jalr
            return 8;

        // pseudo instruction -> is replaced with JAL
        case I_J:
            return 4;

        case I_LI:
            // if the immediate is twelve bits only, the LUI is not needed and only I_ADDI is generated
            if (data->imm <= 0xFFF) {
                return 4;
            }
            // if the lower twelve bits are zero and only the upper bits contain
            // a value, a simple LUI suffices to only load the upper bits
            if ((data->imm & 0xFFF) == 0) {
                return 4;
            }
            // if the immediate value has non-zero bits in both the lower 12 bits
            // and the upper twelve bits, then replace by LUI and ADDI
            // see https://stackoverflow.com/questions/76331514/riscv-li-instruction
            return 8;

        case I_MV:
            return 4;
    }

    return 4;
}

int assemble(const char* filename, uint8_t* machine_code, std::map<uint32_t, uint32_t*>* segments) {

    // this is the address where constants defined by assembler instructions .byte, .half, .word, .dword are placed
    //uint32_t constants_address = 0x00CC0000;
    uint32_t constants_address = 0x00010000;

    reset_asm_line(&parser_asm_line);
    reset_asm_lines(asm_line_array, 100);

    fp_emit = &encoder_callback;

    yyin = fopen(filename, "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", filename);
    }

    yy_flex_debug = 0;
    yydebug = 0;
    yyparse();

    // DEBUG
    printf("\n\nasm_lines after parse: %d\n", asm_line_array_index);
    for (int i = 0; i < asm_line_array_index; i++) {
        //printf("line %d\n", i);
        print_asm_line(&asm_line_array[i]);
    }

//#if 0
    //
    // optimize
    //

    for (int i = 0; i < (asm_line_array_index - 1); i++) {

        //print_asm_line(&asm_line_array[i]);
        //print_asm_line(&asm_line_array[i + 1]);

        //
        // optimization: recombine lui, addi into li so that li can be optimized by the encoder
        //

        asm_line_t* data_1 = &asm_line_array[i];
        asm_line_t* data_2 = &asm_line_array[i + 1];

        if ((!data_1->used) || (!data_2->used)) {
            continue;
        }

        if ((data_1->instruction == I_LUI) && (data_2->instruction == I_ADDI)) {

            printf("found optimization\n", i);

            uint32_t strlength = strlen(data_1->offset_1_expression->string_val);

            // check if the symbol is the same
            if (strncmp(data_1->offset_1_expression->string_val, data_2->offset_2_expression->string_val, strlength) == 0) {

                reset_asm_line(data_1);
                data_1->used = 1;
                data_1->instruction = I_LI;
                data_1->reg_rd = data_2->reg_rd;

                data_1->offset_1_expression = data_2->offset_2_expression;

                // second line is erased
                reset_asm_line(data_2);
            }

        }
    }

    // DEBUG
    printf("\n\nasm_lines after optimize\n");
    for (int i = 0; i < asm_line_array_index; i++) {
        //printf("line %d\n", i);
        print_asm_line(&asm_line_array[i]);
    }
//#endif

    //
    // collect all labels and store them inside the label_address_map.
    // In this step, no real address is inserted. The dummy value 0x00 is inserted.
    //

    tuple_set_element_t label_address_map[20];
    initialize_tuple_set(label_address_map, 20);

    // determine all labels that are defined within this file
    for (int i = 0; i < asm_line_array_index; i++) {

        // if there is a label
        if (strnlen(asm_line_array[i].label, 100) > 0) {

            tuple_set_element_t* tuple_set_element = NULL;
            if (!insert_tuple_set(label_address_map, 20, asm_line_array[i].label, 0x00, &tuple_set_element)) {
                printf("Insert label address mapping failed!\n");
                break;
            }

            asm_line_array[i].tuple_set_element = tuple_set_element;
        }

    }

    //
    // determine instruction sizes and store them into the instructions
    //

    uint32_t current_address = 0;
    int8_t byte_index = 0;

    for (int i = 0; i < asm_line_array_index; i++) {

        // the assembler instructions .byte, .half, .word, and .dword
        // use labels to define constants but these labels do not go into
        // the label map because they are not used to jump to a specific
        // address
        if (asm_line_array[i].asm_instruction != AI_UNDEFINED) {
            continue;
        }

        if (strnlen(asm_line_array[i].label, 100) > 0) {

            // tuple_set_element_t* tuple_set_element = NULL;
            // retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].label, &tuple_set_element);
            //
            // if (tuple_set_element == NULL) {
            //     printf("Retrieving \"%s\" from label address mapping failed!\n", asm_line_array[i].label);
            //     abort();
            // }
            //
            //tuple_set_element->value = current_address;

            asm_line_array[i].tuple_set_element->value = current_address;
        }

        uint32_t label_exists_in_file = 0;
        if (asm_line_array[i].offset_0_expression != NULL) {
            label_exists_in_file = retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, NULL);
        }

        uint32_t instr_size = determine_instruction_size(&asm_line_array[i], label_exists_in_file);
        current_address += instr_size;

        if (asm_line_array[i].instruction != I_UNDEFINED_INSTRUCTION) {
            asm_line_array[i].instruction_index = byte_index;

            byte_index += instr_size;
        }
    }

    // DEBUG
    printf("\n\nlabel map #1:\n");
    print_tuple_set(label_address_map, 20);

    //
    // Process modifiers %hi, %lo
    //

    current_address = 0;

    for (int i = 0; i < asm_line_array_index; i++) {

        asm_line_t* asm_line = &asm_line_array[i];

        switch (asm_line->parameter_modifier_0) {

            case PM_HI:
                printf("Process Modifier 0 - HI\n");
                abort();
                break;

            case PM_LO:
                printf("Process Modifier 0 - LO\n");
                abort();
                break;

            case PM_UNDEFINED:
            default:
                // nop
                break;
        }

        switch (asm_line->parameter_modifier_1) {

            case PM_HI: {

                // %hi(symbol)
                // The high 20 bits of absolute address for symbol.

                printf("Process Modifier 1 - HI on symbol: '%s'\n", asm_line->offset_1_expression->string_val);

                tuple_set_element_t* tuple_set_element = NULL;

                int str_len = strnlen(asm_line->offset_1_expression->string_val, 100);
                int label_found = retrieve_by_key_tuple_set(label_address_map, 20, asm_line->offset_1_expression->string_val, &tuple_set_element);

                if (!label_found) {
                    printf("Label not found!\n");
                    abort();
                }

                uint32_t address = tuple_set_element->value;
                printf("%08" PRIx64 "\n", address);

                reset_offsets_and_modifiers(asm_line);

                asm_line->imm = (address >> 12) & 0xFFFFF;
                asm_line->offset_1 = (address >> 12) & 0xFFFFF; // this is for the LBU instruction which encode offset_1 into imm12

                // TODO:
                // %lo(symbol)
                // The low 12 bits of absolute address for symbol.
                //
                // %hi(symbol)
                // The high 20 bits of absolute address for symbol.

                //asm_line->offset_1 = 1;
                //asm_line->offset_1_expression->int_val = 0x00;
            }
            break;

            case PM_LO: {

                // %lo(symbol)
                // The low 12 bits of absolute address for symbol.

                printf("Process Modifier 1 - LO on symbol: '%s'\n", asm_line->offset_1_expression->string_val);

                tuple_set_element_t* tuple_set_element = NULL;

                int str_len = strnlen(asm_line->offset_1_expression->string_val, 100);
                int label_found = retrieve_by_key_tuple_set(label_address_map, 20, asm_line->offset_1_expression->string_val, &tuple_set_element);

                if (!label_found) {
                    printf("Label not found!\n");
                    abort();
                }

                uint32_t address = tuple_set_element->value;
                //uint32_t address = 278; // hex 116
                printf("%08" PRIx64 "\n", address);

                reset_offsets_and_modifiers(asm_line);

                asm_line->imm = address & 0xFFF;
                asm_line->offset_1 = address & 0xFFF; // this is for the LBU instruction which encode offset_1 into imm12

                // TODO:
                // %lo(symbol)
                // The low 12 bits of absolute address for symbol.
                //
                // %hi(symbol)
                // The high 20 bits of absolute address for symbol.
            }
            break;

            case PM_UNDEFINED:
            default:
                // nop
                break;
        }

        switch (asm_line->parameter_modifier_2) {

            case PM_HI:
                printf("Process Modifier 2 - HI\n");
                abort();
                break;

            case PM_LO:
                printf("Process Modifier 2 - LO\n");
                abort();
                break;

            case PM_UNDEFINED:
            default:
                // nop
                break;
        }

        uint32_t label_exists_in_file = 0;
        if (asm_line_array[i].offset_0_expression != NULL) {
            label_exists_in_file = retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, NULL);
        }

        current_address = current_address + determine_instruction_size(&asm_line_array[i], label_exists_in_file);

    }

    // DEBUG
    printf("\n\nlabel map #2:\n");
    print_tuple_set(label_address_map, 20);

    //
    // Process Assembler Instructions
    //
    // collect all .equ assembler instructions and store them inside the equ_map
    // process assembler instructions: .byte, .half, .word, and .dword
    //

    trivial_map_element_t equ_map[20];
    initialize_trivial_map(equ_map, 20);

    current_address = 0;

    for (int i = 0; i < asm_line_array_index; i++) {

        if (asm_line_array[i].asm_instruction == AI_EQU) {
            //printf("key:%s value:%d\n", asm_line_array[i].asm_instruction_symbol, asm_line_array[i].asm_instruction_expr->int_val);
            if (!insert_or_replace_trivial_map(equ_map, 20,
                    asm_line_array[i].asm_instruction_symbol,
                    asm_line_array[i].asm_instruction_expr->int_val)) {
                printf("Insert .equ failed!\n");
                break;
            }
        }

        // process assembler instructions: .byte, .half, .word, and .dword
        //
        // 1. place constant values into memory
        // 2. retrieve the address, where the constants have been placed
        // 3. Insert the label as a key and the address as a value into the equ map.

        switch (asm_line_array[i].asm_instruction) {

            case AI_BYTE:
            {
                printf("AI_BYTE\n");

                //asm_line_array[i].use_raw_data = 1;
                //asm_line_array[i].raw_data_length = 1;

                if (strnlen(asm_line_array[i].label, 100) != 0) {

                    // get the label which might be stored in the previous line
                    char use_label[100];
                    int use_address = current_address;
                    memset(use_label, 0, 100);
                    memcpy(use_label, asm_line_array[i].label, 100);
                    if (strnlen(asm_line_array[i].label, 100) == 0) {
                        memcpy(use_label, asm_line_array[i - 1].label, 100);
                        use_address -= 4;
                    }

                    if (!insert_tuple_set(label_address_map,
                        20,
                        use_label,
                        use_address,
                        NULL))
                    {
                        printf("Insert .equ failed!\n");
                        abort();
                    }

                }

                current_address += asm_line_array[i].raw_data_length;
            }
            break;

            case AI_HALF: {
                printf("AI_HALF %s, %d\n", __FILE__, __LINE__);
                abort();
            }
            break;

            case AI_WORD:
            {
                int length = 4;

                // the assembler instruction .byte, .half and .word place the
                // data directly into the text segment!
                asm_line_array[i].use_raw_data = 1;
                asm_line_array[i].raw_data_length = length;

                int64_t int_val = asm_line_array[i].asm_instruction_expr->int_val;
                for (int j = 0; j < length; j++) {

                    uint8_t temp = (int_val >> (8*(length-1-j))) & 0xFF;
                    asm_line_array[i].raw_data[j] = temp;
                }

                // get the label which might be stored in the previous line
                char use_label[100];
                int use_address = current_address;
                memset(use_label, 0, 100);
                memcpy(use_label, asm_line_array[i].label, 100);
                if (strnlen(asm_line_array[i].label, 100) == 0) {
                    memcpy(use_label, asm_line_array[i - 1].label, 100);
                    use_address -= 4;
                }

                if (!insert_tuple_set(label_address_map,
                    20,
                    use_label,
                    use_address,
                    NULL))
                {
                    printf("Insert .equ failed!\n");
                    abort();
                }

                current_address += length;

                //printf("key:%s value:%d\n", asm_line_array[i].asm_instruction_symbol,
                //    asm_line_array[i].asm_instruction_expr->int_val);

                //mem_preload_value(segments, equ_map, &asm_line_array[i], constants_address, asm_line_array[i].asm_instruction_expr->int_val, true);
            }
            break;

            case AI_DWORD:
            {
                printf("AI_HALF %s, %d\n", __FILE__, __LINE__);
                abort();

                uint32_t high = (asm_line_array[i].asm_instruction_expr->int_val & 0xFFFFFFFF00000000) >> 32;
                uint32_t low = (asm_line_array[i].asm_instruction_expr->int_val & 0x00000000FFFFFFFF) >> 0;

                // TODO: place data into the code segment

                // mem_preload_value(segments, equ_map, &asm_line_array[i], constants_address, high, true);
                // mem_preload_value(segments, equ_map, &asm_line_array[i], constants_address, low, false);

                current_address += 8;

            }
            break;

            case AI_ASCIZ:
            case AI_STRING:
            {

                printf("String\n");

                int length = strnlen(asm_line_array[i].offset_identifier_0, 100);

                // the assembler instruction .byte, .half and .word place the
                // data directly into the text segment!
                //asm_line_array[i].asm_instruction = AI_UNDEFINED;
                asm_line_array[i].use_raw_data = 1;

                // subtract the two quotes which are only used to delimit the
                // string but will not be placed into the text segment
                asm_line_array[i].raw_data_length = length - 2;
                //asm_line_array[i].raw_data = asm_line_array[i].asm_instruction_expr->int_val;

                uint8_t* string_val = (uint8_t*)asm_line_array[i].offset_identifier_0;

                // remove preceding quotes
                string_val++;

                // iterate for one character less to skip the trailing space
                int index = 0;
                char char_1 = 0;
                char char_2 = 0;
                for (int j = 0; j < length-2; j++) {

                    if (*string_val == '\\') {
                        char_1 = *string_val;

                        string_val++;
                        continue;
                    } else if (char_1 == '\\')  {

                        char_2 = *string_val;

                        if (char_2 == 'n') {
                            asm_line_array[i].raw_data[index] = 0x0A;

                            index++;
                            string_val++;

                            char_1 = 0;
                            char_2 = 0;
                        } else {
                            asm_line_array[i].raw_data[index] = '\\';
                            index++;

                            asm_line_array[i].raw_data[index] = *string_val;
                            index++;

                            char_1 = 0;
                        }
                    } else {

                        asm_line_array[i].raw_data[index] = *string_val;

                        index++;
                        string_val++;
                    }
                }

                // get the label which might be stored in the previous line
                char use_label[100];
                int use_address = current_address;
                memset(use_label, 0, 100);
                memcpy(use_label, asm_line_array[i].label, 100);
                if (strnlen(asm_line_array[i].label, 100) == 0) {
                    memcpy(use_label, asm_line_array[i - 1].label, 100);
                    use_address -= 4;
                }

                if (!insert_tuple_set(label_address_map,
                    20,
                    use_label,
                    use_address,
                    NULL))
                {
                    printf("Insert .equ failed!\n");
                    abort();
                }

                current_address += length;

            }
            break;

            case AI_UNDEFINED:
                // nop
                break;

            default:
                enum assembler_instruction ai = asm_line_array[i].asm_instruction;
                printf("Unknown Assembler Instruction: %s\n", assembler_instruction_to_string(ai));
                break;
        }

        uint32_t label_exists_in_file = 0;
        if (asm_line_array[i].offset_0_expression != NULL) {
            label_exists_in_file = retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, NULL);
        }

        current_address = current_address + determine_instruction_size(&asm_line_array[i], label_exists_in_file);
    }

    // DEBUG
    printf("\n\nlabel map #3:\n");
    print_tuple_set(label_address_map, 20);

    // DEBUG
    printf("\n\nequ map:\n");
    print_trivial_map(equ_map, 20);

    //
    // Replace .equ
    //
    // In each line, check if there is a offset_?_expr, where a symbol is used.
    //
    // The approach is to look for a symbol in the assembler line and blindly
    // assume that the symbol is a defined constant in the equ map. Then try
    // to resolve it from the equ map!
    //

    for (int i = 0; i < asm_line_array_index; i++) {

        asm_line_t* asm_line_ptr = &asm_line_array[i];

        if ((asm_line_ptr->offset_0_expression != NULL) && (strlen(asm_line_ptr->offset_0_expression->string_val) > 0)) {

            //printf("%s\n", asm_line_ptr->offset_0_expression->string_val);
            if (contains_key_trivial_map(equ_map, 20, asm_line_ptr->offset_0_expression->string_val)) {
                int val = 0;
                retrieve_by_key_trivial_map(equ_map, 20, asm_line_ptr->offset_0_expression->string_val, &val);
                asm_line_ptr->offset_0_expression->int_val = val;
                // erase the replaced string
                memset(asm_line_ptr->offset_0_expression->string_val, 0, 100);
            }
            // else {
            //     printf("Cannot resolve equ-symbol \"%s\"!\n", asm_line_ptr->offset_0_expression->string_val);
            // }

        } else if ((asm_line_ptr->offset_1_expression != NULL) && (strlen(asm_line_ptr->offset_1_expression->string_val) > 0)) {

            //printf("%s\n", asm_line_ptr->offset_1_expression->string_val);
            if (contains_key_trivial_map(equ_map, 20, asm_line_ptr->offset_1_expression->string_val)) {
                int val = 0;
                retrieve_by_key_trivial_map(equ_map, 20, asm_line_ptr->offset_1_expression->string_val, &val);
                asm_line_ptr->offset_1_expression->int_val = val;
                // erase the replaced string
                memset(asm_line_ptr->offset_1_expression->string_val, 0, 100);
            }
            // else {
            //     printf("Cannot resolve equ-symbol \"%s\"!\n", asm_line_ptr->offset_1_expression->string_val);
            // }

        } else if ((asm_line_ptr->offset_2_expression != NULL) && (strlen(asm_line_ptr->offset_2_expression->string_val) > 0)) {

            //printf("%s\n", asm_line_ptr->offset_2_expression->string_val);
            if (contains_key_trivial_map(equ_map, 20, asm_line_ptr->offset_2_expression->string_val)) {
                int val = 0;
                retrieve_by_key_trivial_map(equ_map, 20, asm_line_ptr->offset_2_expression->string_val, &val);
                asm_line_ptr->offset_2_expression->int_val = val;
                // erase the replaced string
                memset(asm_line_ptr->offset_2_expression->string_val, 0, 100);
            }
            // else {
            //     printf("Cannot resolve equ-symbol \"%s\"!\n", asm_line_ptr->offset_2_expression->string_val);
            // }

        }

        if (asm_line_ptr->offset_0_used && (strlen(asm_line_ptr->offset_identifier_0) > 0)) {

            printf("offset 0\n");

            int val = 0;
            retrieve_by_key_trivial_map(equ_map, 20, asm_line_ptr->offset_identifier_0, &val);
            asm_line_ptr->offset_0 = val;

        } else if (asm_line_ptr->offset_1_used && (strlen(asm_line_ptr->offset_identifier_1) > 0)) {

            printf("offset 1\n");

            int val = 0;
            retrieve_by_key_trivial_map(equ_map, 20, asm_line_ptr->offset_identifier_1, &val);
            asm_line_ptr->offset_1 = val;

        } else if (asm_line_ptr->offset_2_used && (strlen(asm_line_ptr->offset_identifier_2) > 0)) {

            printf("offset 2\n");

            int val = 0;
            retrieve_by_key_trivial_map(equ_map, 20, asm_line_ptr->offset_identifier_2, &val);
            asm_line_ptr->offset_2 = val;

        }

    }

    //
    // replace labels in lines
    //

    uint32_t address = 0;

    for (int i = 0; i < asm_line_array_index; i++) {

        // // DEBUG
        // if (asm_line_array[i].instruction == I_J) {
        //      printf("abx\n");
        // }

        address += determine_instruction_size(&asm_line_array[i], 1);

        if (asm_line_array[i].offset_0_used && strnlen(asm_line_array[i].offset_identifier_0, 100) > 0) {

            printf("offset_identifier_0 found: %s\n", asm_line_array[i].offset_identifier_0);

            // if (contains_key_trivial_map(equ_map, 20, asm_line_array[i].offset_identifier_0)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(equ_map, 20, asm_line_array[i].offset_identifier_0, &value);
            //     asm_line_array[i].offset_0 = value;
            // }
            // if (contains_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_identifier_0)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_identifier_0, &value);
            //     asm_line_array[i].offset_0 = value;
            // }

            // memset(asm_line_array[i].offset_identifier_0, 0, 100);
        }
        if (asm_line_array[i].offset_1_used && strnlen(asm_line_array[i].offset_identifier_1, 100) > 0) {

            printf("offset_identifier_1 found: %s\n", asm_line_array[i].offset_identifier_1);

            // if (contains_key_trivial_map(equ_map, 20, asm_line_array[i].offset_identifier_1)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(equ_map, 20, asm_line_array[i].offset_identifier_1, &value);
            //     asm_line_array[i].offset_1 = value;
            // }
            // if (contains_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_identifier_1)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_identifier_1, &value);
            //     asm_line_array[i].offset_1 = value;
            // }

            // memset(asm_line_array[i].offset_identifier_1, 0, 100);
        }
        if (asm_line_array[i].offset_2_used && strnlen(asm_line_array[i].offset_identifier_2, 100) > 0) {

            printf("offset_identifier_2 found: %s\n", asm_line_array[i].offset_identifier_2);

            // if (contains_key_trivial_map(equ_map, 20, asm_line_array[i].offset_identifier_2)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(equ_map, 20, asm_line_array[i].offset_identifier_2, &value);
            //     asm_line_array[i].offset_2 = value;
            // }
            // if (contains_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_identifier_2)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_identifier_2, &value);
            //     asm_line_array[i].offset_2 = value;
            // }

            // memset(asm_line_array[i].offset_identifier_2, 0, 100);
        }

        if (asm_line_array[i].offset_0_expression != NULL && strnlen(asm_line_array[i].offset_0_expression->string_val, 100) > 0) {

            //printf("offset_0_expression found: %s\n", asm_line_array[i].offset_0_expression->string_val);

            uint32_t str_len = strlen(asm_line_array[i].offset_0_expression->string_val);
            char* last_character = asm_line_array[i].offset_0_expression->string_val + str_len - 1;

            tuple_set_element_t* tuple_set_element = NULL;

            if (strncmp(last_character, "f", 1) == 0) {
                retrieve_by_key_greater_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_0 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_0 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_0_used = 1;
                } else {
                    printf("greater_than \"%s\" label not defined!\n", asm_line_array[i].offset_0_expression->string_val);
                    abort();
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_0 = tuple_set_element->value - ((asm_line_array[i].instruction_index - 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_0 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_0_used = 1;
                } else {
                    printf("less_than \"%s\" label not defined!\n", asm_line_array[i].offset_0_expression->string_val);
                    abort();
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    // convert the target label address into a relative value (relative to the current assembler line)
                    // since the branch instructions work by adding an offset to the current pc so they are inherently
                    // pc-relative jumps and the immediate value has to be a pc-relative value
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_0 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_0 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_0_used = 1;
                } else {
                    printf("direct_match \"%s\" label not defined!\n", asm_line_array[i].offset_0_expression->string_val);
                    abort();
                }
            }
        }
        if (asm_line_array[i].offset_1_expression != NULL && strnlen(asm_line_array[i].offset_1_expression->string_val, 100) > 0) {

            printf("offset_1_expression found: %s\n", asm_line_array[i].offset_1_expression->string_val);

            uint32_t str_len = strlen(asm_line_array[i].offset_1_expression->string_val);
            char* last_character = asm_line_array[i].offset_1_expression->string_val + str_len - 1;

            tuple_set_element_t* tuple_set_element = NULL;

            if (strncmp(last_character, "f", 1) == 0) {
                retrieve_by_key_greater_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("greater_than: %d\n", tuple_set_element->value);
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_1 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_1 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_1_used = 1;
                } else {
                    printf("greater_than \"%s\" label not defined!\n", asm_line_array[i].offset_1_expression->string_val);
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("less_than: %d\n", tuple_set_element->value);
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_1 = tuple_set_element->value - ((asm_line_array[i].instruction_index - 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_1 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_1_used = 1;
                } else {
                    printf("less_than \"%s\" label not defined!\n", asm_line_array[i].offset_1_expression->string_val);
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("direct_match: %d\n", tuple_set_element->value);
                    // convert the target label address into a relative value (relative to the current assembler line)
                    // since the branch instructions work by adding an offset to the current pc so they are inherently
                    // pc-relative jumps and the immediate value has to be a pc-relative value
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_1 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_1 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_1_used = 1;
                } else {
                    printf("direct_match \"%s\" label not defined!\n", asm_line_array[i].offset_1_expression->string_val);
                }
            }
        }
        if (asm_line_array[i].offset_2_expression != NULL && strnlen(asm_line_array[i].offset_2_expression->string_val, 100) > 0) {

            //printf("offset_2_expression found: %s\n", asm_line_array[i].offset_2_expression->string_val);

            uint32_t str_len = strlen(asm_line_array[i].offset_2_expression->string_val);
            char* last_character = asm_line_array[i].offset_2_expression->string_val + str_len - 1;

            tuple_set_element_t* tuple_set_element = NULL;

            if (strncmp(last_character, "f", 1) == 0) {
                retrieve_by_key_greater_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_2 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_2 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("greater_than \"%s\" label not defined!\n", asm_line_array[i].offset_2_expression->string_val);
                    abort();
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_2 = tuple_set_element->value - ((asm_line_array[i].instruction_index - 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_2 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("less_than \"%s\" label not defined!\n", asm_line_array[i].offset_2_expression->string_val);
                    abort();
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    // convert the target label address into a relative value (relative to the current assembler line)
                    // since the branch instructions work by adding an offset to the current pc so they are inherently
                    // pc-relative jumps and the immediate value has to be a pc-relative value
                    switch (asm_line_array[i].instruction_type) {
                        case IT_B:
                        case IT_J:
                        case IT_P:
                            asm_line_array[i].offset_2 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * FACTOR);
                            break;
                        default:
                            asm_line_array[i].offset_2 = tuple_set_element->value;
                            break;
                    }
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("direct_match \"%s\" label not defined!\n", asm_line_array[i].offset_2_expression->string_val);
                    abort();
                }
            }
        }
    }

    //
    // DEBUG - asm_lines after replace labels
    //

    printf("\n\n");
    printf("asm_lines after replace labels: %d\n", 100);
    for (int i = 0; i < 100; i++) {
        //printf("line %d\n", i);
        if (asm_line_array[i].used != 0) {
            print_asm_line(&asm_line_array[i]);
        }
    }

    //
    // Replace Pseudo instructions
    //

    for (int i = 0; i < 100; i++) {
        resolve_pseudo_instructions_asm_line(asm_line_array, 100, i);
    }

    // // DEBUG
    // printf("\n\n");
    // printf("asm_lines after replace pseudo instructions: %d\n", 100);
    // for (int i = 0; i < 100; i++) {
    //     //printf("line %d\n", i);
    //     if (asm_line_array[i].used != 0) {
    //         print_asm_line(&asm_line_array[i]);
    //     }
    // }

    // print code
    printf("\n\n");
    printf("code:\n");
    for (int i = 0; i < 100; i++) {
        //printf("line %d\n", i);
        if ((asm_line_array[i].used != 0) && (asm_line_array[i].instruction != I_UNDEFINED_INSTRUCTION)) {
            //printf("%d) ", i);
            printf("%d) ", asm_line_array[i].instruction_index * FACTOR);
            serialize_asm_line(&asm_line_array[i]);
        }
    }

    // encode all lines
    printf("\n\n");
    printf("machine code:\n");

    byte_index = 0;
    for (int i = 0; i < 100; i++) {

        //printf("line %d\n", i);

        asm_line_t* asm_line = &asm_line_array[i];

        // encode RISC-V instructions, but also encode assembler instructions
        // if they place data into the .text segment like .byte, .half, .word,  .dword
        if (asm_line->used == 1)
        {

            if (asm_line->instruction == I_UNDEFINED_INSTRUCTION)
            {

                switch (asm_line->asm_instruction)
                {
                    case AI_BYTE:
                    {
                        printf("AI_BYTE %s, %d\n", __FILE__, __LINE__);

                        for (int j = 0; j < asm_line->raw_data_length; j++) {

                            uint8_t machine_code_for_instruction = asm_line->raw_data[j];

                            machine_code[byte_index] = machine_code_for_instruction;
                            byte_index += sizeof(uint8_t);

                        }
                    }
                    break;

                    case AI_HALF:
                    {
                        printf("AI_HALF %s, %d\n", __FILE__, __LINE__);
                        abort();
                    }
                    break;

                    case AI_WORD: {
                        //printf("AI_WORD\n");

                        uint32_t machine_code_for_instruction = asm_line->raw_data[0] << 24 | asm_line->raw_data[1] << 16 | asm_line->raw_data[2] << 8 | asm_line->raw_data[3] << 0;

                        //printf("%d) %08" PRIx64 "\n", instruction_index, machine_code_for_instruction);
                        printf("%08" PRIx64 "\n", machine_code_for_instruction);

                        machine_code[byte_index] = machine_code_for_instruction;
                        byte_index += sizeof(uint32_t);
                    }
                    break;

                    case AI_DWORD:
                        printf("AI_DWORD\n");
                        break;

                    case AI_ASCIZ:
                    case AI_STRING:
                    {
                        //printf("%d\n", encode(&asm_line_array[i]));

                        uint32_t stop_data = 0x00;
                        if (asm_line->use_raw_data)
                        {
                            for (int j = 0; j < asm_line->raw_data_length; j++)
                            {
                                machine_code[byte_index] = asm_line->raw_data[j];
                                byte_index += sizeof(uint8_t);
                            }

                            // add zero termination of string data
                            machine_code[byte_index] = 0x00;
                            byte_index += sizeof(uint8_t);
                        }
                    }
                    break;
                }
            }
            else
            {
                uint32_t machine_code_for_instruction = encode(&asm_line_array[i]);
                if (machine_code_for_instruction != 0)
                {
                    //printf("%d) %08" PRIx64 "\n", instruction_index, machine_code_for_instruction);
                    printf("%08" PRIx64 "\n", machine_code_for_instruction);

                    for (int j = 0; j < 4; j++) {

                        machine_code[byte_index] = (machine_code_for_instruction & 0xFF);
                        byte_index += 1;

                        machine_code_for_instruction >>= 8;
                    }


                }

            }
        }
    }

/*
    //
    // DEBUG
    //

    char test_key[100];
    strncpy(test_key, "IO_BASE", 100);
    if (contains_key_trivial_map(equ_map, 20, test_key)) {
        printf("contains\n");
    } else {
        printf("does not contain\n");
    }

    //insert_or_replace_trivial_map(equ_map, 20, test_key, 17);
    //print_trivial_map(equ_map, 20);

    char test_key_not_contained[100];
    strncpy(test_key_not_contained, "test", 100);
    int retrieved_value = 0;
    int retrieved = retrieve_by_key_trivial_map(equ_map, 20, test_key_not_contained, &retrieved_value);
    printf("retrieved: %d, value: %d\n", retrieved, retrieved_value);
*/

    return byte_index;
}

// //#define DBUILD_ASSEMBLER 1
// #ifdef DBUILD_ASSEMBLER

// int main(int argc, char **argv)
// {
//     uint32_t machine_code[100];
//     memset(machine_code, 0, 100);

//     assemble(argv[1], machine_code);

//     return 0;
// }

// #endif