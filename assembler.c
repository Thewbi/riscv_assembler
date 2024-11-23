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

uint32_t determine_instruction_size(asm_line_t* data) {

    if (data->instruction == I_UNDEFINED_INSTRUCTION) {
        return 0;
    }

    switch (data->instruction) {

        case I_CALL:
            return 8;

        // pseudo instruction -> is replaced with JAL
        case I_J:
            return 4;

        case I_LI:
            if (data->imm <= 0xFFF) {
                return 4;
            }
            return 8;

        case I_MV:
            return 4;
    }

    return 4;
}

int assemble(const char* filename, uint32_t* machine_code, std::map<uint32_t, uint32_t*>* segments) {

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

    // // DEBUG
    // printf("asm_lines after parse: %d\n", asm_line_array_index);
    // for (int i = 0; i < asm_line_array_index; i++) {
    //     //printf("line %d\n", i);
    //     print_asm_line(&asm_line_array[i]);
    // }


    //
    // collect all labels and store them inside the label_address_map
    //

    // trivial_map_element_t label_address_map[20];
    // initialize_trivial_map(label_address_map, 20);

    tuple_set_element_t label_address_map[20];
    initialize_tuple_set(label_address_map, 20);

    int current_address = 0x0000;
    int32_t instruction_index = 0;

    for (int i = 0; i < asm_line_array_index; i++) {

        // the assembler instructions .byte, .half, .word, and .dword
        // use labels to define constants but these labels do not go into
        // the label map because they are not used to jump to a specific
        // address
        if (asm_line_array[i].asm_instruction != AI_UNDEFINED) {
            continue;
        }

        if (strnlen(asm_line_array[i].label, 100) > 0) {

            // printf("line_nr:%d label:%s address:%d address/4:%d size_in_bytes:%d\n",
            //     asm_line_array[i].line_nr,
            //     asm_line_array[i].label,
            //     current_address,
            //     current_address/4,
            //     asm_line_array[i].size_in_bytes);

            // if (contains_key_trivial_map(label_address_map, 20, asm_line_array[i].label)) {
            //     printf("Label is already contained: %s\n", asm_line_array[i].label);
            // }

            // if (!insert_or_replace_trivial_map(label_address_map, 20, asm_line_array[i].label, current_address)) {
            //     printf("Insert label address mapping failed!\n");
            //     break;
            // }

            if (!insert_tuple_set(label_address_map, 20, asm_line_array[i].label, current_address)) {
                printf("Insert label address mapping failed!\n");
                break;
            }
        }
        //else {
            //printf("size_in_bytes:%d\n", asm_line_array[i].size_in_bytes);
        //}

        //printf("current_address: %d, determine_instruction_size: %d\n", current_address, determine_instruction_size(&asm_line_array[i]));

        current_address = current_address + determine_instruction_size(&asm_line_array[i]);

        if (asm_line_array[i].instruction != I_UNDEFINED_INSTRUCTION) {
            asm_line_array[i].instruction_index = instruction_index;
            instruction_index++;
        }
    }

    // DEBUG
    printf("\n");
    printf("label map:\n");
    //print_trivial_map(label_address_map, 20);
    print_tuple_set(label_address_map, 20);

    //
    // collect all .equ assembler instructions and store them inside the equ_map
    //

    trivial_map_element_t equ_map[20];
    initialize_trivial_map(equ_map, 20);

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
        // 3. Insert the label as a key and the address as a value into the
        //    equ map.
        if ( (asm_line_array[i].asm_instruction == AI_BYTE) ||
                (asm_line_array[i].asm_instruction == AI_HALF) ||
                (asm_line_array[i].asm_instruction == AI_WORD)) {

            //printf("key:%s value:%d\n", asm_line_array[i].asm_instruction_symbol, asm_line_array[i].asm_instruction_expr->int_val);

            mem_preload_value(segments, equ_map, &asm_line_array[i], constants_address, asm_line_array[i].asm_instruction_expr->int_val, true);

        } else if (asm_line_array[i].asm_instruction == AI_DWORD) {

            uint32_t high = (asm_line_array[i].asm_instruction_expr->int_val & 0xFFFFFFFF00000000) >> 32;
            uint32_t low = (asm_line_array[i].asm_instruction_expr->int_val & 0x00000000FFFFFFFF) >> 0;

            mem_preload_value(segments, equ_map, &asm_line_array[i], constants_address, high, true);
            mem_preload_value(segments, equ_map, &asm_line_array[i], constants_address, low, false);

        }
    }

    // DEBUG
    printf("\n");
    printf("equ map:\n");
    print_trivial_map(equ_map, 20);

    //
    // Replace .equ
    //
    // In each line, check if there is a offset_?_expr, where a symbol is used.
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

    }

    //
    // replace labels in lines
    //

    uint32_t address = 0;

    for (int i = 0; i < asm_line_array_index; i++) {

        if (asm_line_array[i].instruction == I_J) {
            printf("abx\n");
        }

        address += determine_instruction_size(&asm_line_array[i]);

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
                    //printf("greater_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_0 = tuple_set_element->value;
                    asm_line_array[i].offset_0_used = 1;
                } else {
                    printf("greater_than \"%s\" label not defined!\n", asm_line_array[i].offset_0_expression->string_val);
                    abort();
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    //printf("less_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_0 = tuple_set_element->value;
                    asm_line_array[i].offset_0_used = 1;
                } else {
                    printf("less_than \"%s\" label not defined!\n", asm_line_array[i].offset_0_expression->string_val);
                    abort();
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    //printf("direct_match: %d\n", tuple_set_element->value);
                    //asm_line_array[i].offset_0 = tuple_set_element->value;

                    // convert the target label address into a relative value (relative to the current assembler line)
                    // since the branch instructions work by adding an offset to the current pc so they are inherently
                    // pc-relative jumps and the immediate value has to be a pc-relative value
                    asm_line_array[i].offset_0 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * 4);
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
                    asm_line_array[i].offset_1 = tuple_set_element->value;
                    asm_line_array[i].offset_1_used = 1;
                } else {
                    printf("greater_than \"%s\" label not defined!\n", asm_line_array[i].offset_1_expression->string_val);
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("less_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_1 = tuple_set_element->value;
                    asm_line_array[i].offset_1_used = 1;
                } else {
                    printf("less_than \"%s\" label not defined!\n", asm_line_array[i].offset_1_expression->string_val);
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("direct_match: %d\n", tuple_set_element->value);
                    //asm_line_array[i].offset_1 = tuple_set_element->value;

                    // convert the target label address into a relative value (relative to the current assembler line)
                    // since the branch instructions work by adding an offset to the current pc so they are inherently
                    // pc-relative jumps and the immediate value has to be a pc-relative value
                    asm_line_array[i].offset_1 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * 4);
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
                    //printf("greater_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_2 = tuple_set_element->value;
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("greater_than \"%s\" label not defined!\n", asm_line_array[i].offset_2_expression->string_val);
                    abort();
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    //printf("less_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_2 = tuple_set_element->value;
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("less_than \"%s\" label not defined!\n", asm_line_array[i].offset_2_expression->string_val);
                    abort();
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {

                    //printf("direct_match: %d\n", tuple_set_element->value);
                    //asm_line_array[i].offset_2 = tuple_set_element->value;

                    // convert the target label address into a relative value (relative to the current assembler line)
                    // since the branch instructions work by adding an offset to the current pc so they are inherently
                    // pc-relative jumps and the immediate value has to be a pc-relative value
                    asm_line_array[i].offset_2 = tuple_set_element->value - ((asm_line_array[i].instruction_index + 0) * 4);
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("direct_match \"%s\" label not defined!\n", asm_line_array[i].offset_2_expression->string_val);
                    abort();
                }
            }
        }
    }

    // // DEBUG
    // printf("\n\n");
    // printf("asm_lines after replace labels: %d\n", 100);
    // for (int i = 0; i < 100; i++) {
    //     //printf("line %d\n", i);
    //     if (asm_line_array[i].used != 0) {
    //         print_asm_line(&asm_line_array[i]);
    //     }
    // }

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
            printf("%d) ", asm_line_array[i].instruction_index * 4);
            serialize_asm_line(&asm_line_array[i]);
        }
    }

    // encode all lines
    printf("\n\n");
    printf("machine code:\n");

    instruction_index = 0;
    for (int i = 0; i < 100; i++) {
        //printf("line %d\n", i);
        if ((asm_line_array[i].used != 0) && (asm_line_array[i].instruction != I_UNDEFINED_INSTRUCTION)) {
            //printf("%d\n", encode(&asm_line_array[i]));

            uint32_t machine_code_for_instruction = encode(&asm_line_array[i]);
            if (machine_code_for_instruction != 0) {
                //printf("%d) %08" PRIx64 "\n", i, machine_code_for_instruction);
                printf("%08" PRIx64 "\n", machine_code_for_instruction);

                machine_code[instruction_index] = machine_code_for_instruction;
                instruction_index++;
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

    return 0;

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