#include "asm_line.h"

void reset_asm_line(asm_line_t *data) {

    data->instruction = I_UNDEFINED_INSTRUCTION;

    data->reg_1 = R_UNDEFINED_REGISTER;
    data->reg_2 = R_UNDEFINED_REGISTER;
    data->reg_3 = R_UNDEFINED_REGISTER;
}

void print_asm_line(const asm_line_t *data) {

    printf("[Instr: %s]\n", instruction_to_string(data->instruction));

}

const char* instruction_to_string(enum instruction data) {

    switch(data) {
        case I_ADD: return "ADD";
        
        default: return "UNKNOWN";
    }
} 