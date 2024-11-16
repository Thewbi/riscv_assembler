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

int assemble(const char* filename, uint32_t* machine_code) {

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
    printf("asm_lines after parse: %d\n", asm_line_array_index);
    for (int i = 0; i < asm_line_array_index; i++) {
        //printf("line %d\n", i);
        print_asm_line(&asm_line_array[i]);
    }

    //
    // collect all labels and store them inside the label_address_map
    //

    // trivial_map_element_t label_address_map[20];
    // initialize_trivial_map(label_address_map, 20);

    tuple_set_element_t label_address_map[20];
    initialize_tuple_set(label_address_map, 20);

    int current_address = 0x0000;

    for (int i = 0; i < asm_line_array_index; i++) {

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

        current_address = current_address + asm_line_array[i].size_in_bytes;
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
            if (!insert_or_replace_trivial_map(equ_map, 20, asm_line_array[i].asm_instruction_symbol, asm_line_array[i].asm_instruction_expr->int_val)) {
                printf("Insert .equ failed!\n");
                break;
            }
        }
    }

    // DEBUG
    printf("\n");
    printf("equ map:\n");
    print_trivial_map(equ_map, 20);

    //
    // replace labels in lines
    //

    //printf("Replace\n");

    uint32_t address = 0;

    for (int i = 0; i < asm_line_array_index; i++) {

        address += asm_line_array[i].size_in_bytes;

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

            printf("offset_0_expression found: %s\n", asm_line_array[i].offset_0_expression->string_val);

            uint32_t str_len = strlen(asm_line_array[i].offset_0_expression->string_val);
            char* last_character = asm_line_array[i].offset_0_expression->string_val + str_len - 1;

            tuple_set_element_t* tuple_set_element;

            if (strncmp(last_character, "f", 1) == 0) {
                retrieve_by_key_greater_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("greater_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_0 = tuple_set_element->value;
                    asm_line_array[i].offset_0_used = 1;
                } else {
                    printf("greater_than: NotFound\n");
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("less_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_0 = tuple_set_element->value;
                    asm_line_array[i].offset_0_used = 1;
                } else {
                    printf("less_than: NotFound\n");
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("direct_match: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_0 = tuple_set_element->value;
                    asm_line_array[i].offset_0_used = 1;
                } else {
                    printf("direct_match: NotFound\n");
                }
            }

            // asm_line_array[i].offset_0_used = 1;

            // if (contains_key_trivial_map(equ_map, 20, asm_line_array[i].offset_0_expression->string_val)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(equ_map, 20, asm_line_array[i].offset_0_expression->string_val, &value);
            //     asm_line_array[i].offset_0 = value;
            // }
            // if (contains_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_0_expression->string_val, &value);
            //     asm_line_array[i].offset_0 = value;
            // }

            // free(asm_line_array[i].offset_0_expression);
            // asm_line_array[i].offset_0_expression = NULL;
        }
        if (asm_line_array[i].offset_1_expression != NULL && strnlen(asm_line_array[i].offset_1_expression->string_val, 100) > 0) {

            printf("offset_1_expression found: %s\n", asm_line_array[i].offset_1_expression->string_val);

            uint32_t str_len = strlen(asm_line_array[i].offset_1_expression->string_val);
            char* last_character = asm_line_array[i].offset_1_expression->string_val + str_len - 1;

            tuple_set_element_t* tuple_set_element;

            if (strncmp(last_character, "f", 1) == 0) {
                retrieve_by_key_greater_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("greater_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_1 = tuple_set_element->value;
                    asm_line_array[i].offset_1_used = 1;
                } else {
                    printf("greater_than: NotFound\n");
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("less_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_1 = tuple_set_element->value;
                    asm_line_array[i].offset_1_used = 1;
                } else {
                    printf("less_than: NotFound\n");
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("direct_match: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_1 = tuple_set_element->value;
                    asm_line_array[i].offset_1_used = 1;
                } else {
                    printf("direct_match: NotFound\n");
                }
            }

            // asm_line_array[i].offset_1_used = 1;

            // if (contains_key_trivial_map(equ_map, 20, asm_line_array[i].offset_1_expression->string_val)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(equ_map, 20, asm_line_array[i].offset_1_expression->string_val, &value);
            //     asm_line_array[i].offset_1 = value;
            // }
            // if (contains_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_1_expression->string_val, &value);
            //     asm_line_array[i].offset_1 = value;
            // }

            // free(asm_line_array[i].offset_1_expression);
            // asm_line_array[i].offset_1_expression = NULL;
        }
        if (asm_line_array[i].offset_2_expression != NULL && strnlen(asm_line_array[i].offset_2_expression->string_val, 100) > 0) {

            printf("offset_2_expression found: %s\n", asm_line_array[i].offset_2_expression->string_val);

            uint32_t str_len = strlen(asm_line_array[i].offset_2_expression->string_val);
            char* last_character = asm_line_array[i].offset_2_expression->string_val + str_len - 1;

            tuple_set_element_t* tuple_set_element;

            if (strncmp(last_character, "f", 1) == 0) {
                retrieve_by_key_greater_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("greater_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_2 = tuple_set_element->value;
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("greater_than: NotFound\n");
                }
            } else if (strncmp(last_character, "b", 1) == 0) {
                retrieve_by_key_less_than_value_tuple_set(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, str_len-1, address, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("less_than: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_2 = tuple_set_element->value;
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("less_than: NotFound\n");
                }
            } else {
                retrieve_by_key_tuple_set(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, &tuple_set_element);
                if (tuple_set_element != NULL) {
                    printf("direct_match: %d\n", tuple_set_element->value);
                    asm_line_array[i].offset_2 = tuple_set_element->value;
                    asm_line_array[i].offset_2_used = 1;
                } else {
                    printf("direct_match: NotFound\n");
                }
            }

            // asm_line_array[i].offset_2_used = 1;

            // if (contains_key_trivial_map(equ_map, 20, asm_line_array[i].offset_2_expression->string_val)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(equ_map, 20, asm_line_array[i].offset_2_expression->string_val, &value);
            //     asm_line_array[i].offset_2 = value;
            // }
            // if (contains_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val)) {
            //     int value = 0;
            //     retrieve_by_key_trivial_map(label_address_map, 20, asm_line_array[i].offset_2_expression->string_val, &value);
            //     asm_line_array[i].offset_2 = value;
            // }

            // free(asm_line_array[i].offset_2_expression);
            // asm_line_array[i].offset_2_expression = NULL;
        }
    }

    // DEBUG
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
        if (i == 43) {
            printf("\n");
        }
        resolve_pseudo_instructions_asm_line(asm_line_array, 100, i);
    }

    // DEBUG
    printf("\n\n");
    printf("asm_lines after replace pseudo instructions: %d\n", 100);
    for (int i = 0; i < 100; i++) {
        //printf("line %d\n", i);
        if (asm_line_array[i].used != 0) {
            print_asm_line(&asm_line_array[i]);
        }
    }

    // print code
    printf("\n\n");
    printf("code:\n");
    for (int i = 0; i < 100; i++) {
        //printf("line %d\n", i);
        if (asm_line_array[i].used != 0) {
            serialize_asm_line(&asm_line_array[i]);
        }
    }

    // encode all lines
    printf("\n\n");
    printf("machine code:\n");

    size_t instruction_index = 0;
    for (int i = 0; i < 100; i++) {
        //printf("line %d\n", i);
        if (asm_line_array[i].used != 0) {
            //printf("%d\n", encode(&asm_line_array[i]));

            uint32_t machine_code_for_instruction = encode(&asm_line_array[i]);
            if (machine_code_for_instruction != 0) {
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