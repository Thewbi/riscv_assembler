#include "asm_line.h"

void reset_asm_line(asm_line_t *data) {

    data->instruction = I_UNDEFINED_INSTRUCTION;

    data->reg_1 = R_UNDEFINED_REGISTER;
    data->reg_2 = R_UNDEFINED_REGISTER;
    data->reg_3 = R_UNDEFINED_REGISTER;
}

void insert_register(asm_line_t *data, enum register_ reg) {

    if (R_UNDEFINED_REGISTER == data->reg_1) {
        data->reg_1 = reg;
        return;
    }
    if (R_UNDEFINED_REGISTER == data->reg_2) {
        data->reg_2 = reg;
        return;
    }
    if (R_UNDEFINED_REGISTER == data->reg_3) {
        data->reg_3 = reg;
        return;
    }
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