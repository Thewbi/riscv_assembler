#include "asm_line.h"

void reset_asm_line(asm_line_t *data) {

    data->instruction = I_UNDEFINED_INSTRUCTION;
    data->instruction_type = IT_UNDEFINED_INSTRUCTION;

    data->reg_rd = R_UNDEFINED_REGISTER;
    data->reg_rs1 = R_UNDEFINED_REGISTER;
    data->reg_rs2 = R_UNDEFINED_REGISTER;

    data->imm = 0;

    data->offset_0 = 0;
    data->offset_1 = 0;
    data->offset_2 = 0;

    data->offset_0_used = 0;
    data->offset_1_used = 0;
    data->offset_2_used = 0;
}

void insert_register(asm_line_t *data, enum register_ reg) {

    if (data->instruction_type == IT_B || data->instruction_type == IT_S) {

        if (R_UNDEFINED_REGISTER == data->reg_rs1) {
            data->reg_rs1 = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs2) {
            data->reg_rs2 = reg;
            return;
        }

    } else {

        if (R_UNDEFINED_REGISTER == data->reg_rd) {
            data->reg_rd = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs1) {
            data->reg_rs1 = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs2) {
            data->reg_rs2 = reg;
            return;
        }

    }
}

void insert_offset(asm_line_t *data, uint32_t offset, uint8_t index) {
    //printf("ASM_LINE: insert_offset - offset_value: %d offset_index: %d\n", offset, index);
    switch(index) {
        case 0: data->offset_0 = offset; data->offset_0_used = 1; break;
        case 1: data->offset_1 = offset; data->offset_1_used = 1; break;
        case 2: data->offset_2 = offset; data->offset_2_used = 1; break;
        default:
            break;
    }
}

void insert_integer_immediate(asm_line_t *data, uint32_t imm) {

    if (data->instruction == I_LI || data->instruction == I_J || data->instruction == I_CALL) {

        // DEBUG
        //printf("ASM_LINE LI: insert_integer_immediate: %d\n", imm);
        //printf("ASM_LINE LI: 0x%" PRIx64 "\n", imm);
        //printf("ASM_LINE LI: %08" PRIx32 "\n", imm);
        data->imm = imm;

        return;
    }
    
    // DEBUG
    //printf("ASM_LINE: insert_integer_immediate: %d\n", imm);
    
    uint32_t sign_extended = sign_extend_20_bit_to_uint32_t(imm);
    data->imm = sign_extended;
}

void print_asm_line(const asm_line_t *data) {
    printf("[Instr: %s 0:{offset_used:%d offset:%d register:%s} 1:{offset_used:%d offset:%d register:%s} 2:{offset_used:%d offset:%d register:%s}]\n", 
        instruction_to_string(data->instruction), 
        data->offset_0_used, data->offset_0, register_to_string(data->reg_rd),
        data->offset_1_used, data->offset_1, register_to_string(data->reg_rs1),
        data->offset_2_used, data->offset_2, register_to_string(data->reg_rs2));
}

const char* instruction_to_string(enum instruction data) {

    switch(data) {

        case I_ADD: return "ADD";
        case I_ADDI: return "ADDI";
        case I_ANDI: return "ANDI";
        case I_AUIPC: return "AUIPC";

        case I_BEQ: return "BEQ";
        case I_BGE: return "BGE";

        case I_CALL: return "CALL"; // pseudo instruction

        case I_J: return "J"; // pseudo instruction
        case I_JAL: return "JAL";
        case I_JALR: return "JALR";

        case I_LB: return "LB";
        case I_LH: return "LH";
        case I_LBU: return "LBU";
        case I_LHU: return "LHU";
        case I_LI: return "LI";
        case I_LUI: return "LUI";
        case I_LW: return "LW";

        case I_MUL: return "MUL";
        case I_MV: return "MV"; // pseudo instruction

        case I_ORI: return "ORI";

        case I_SLLI: return "SLLI";
        case I_SRLI: return "SRLI";
        case I_SLTIU: return "SLTIU";
        case I_SW: return "SW";

        case I_XORI: return "XORI";
        
        default: return "UNKNOWN";
    }
}

const char* register_to_string(enum register_ data) {

    switch(data) {
        case R_ZERO: return "R_ZERO"; // 0, Hard-wired zero
        case R_RA: return "R_RA"; // 1, Return address
        case R_SP: return "R_SP"; // 2, Stack pointer
        case R_GP: return "R_GP"; // 3, Global pointer
        case R_TP: return "R_TP"; // 4, Thread pointer
        case R_T0: return "R_T0"; // 5, Temporary/alternate link register
        case R_T1: return "R_T1"; // 6, Temporary
        case R_T2: return "R_T2"; // 7, Temporary
        case R_S0: return "R_S0"; // 8, Saved register/frame pointer
        case R_S1: return "R_S1"; // 9, Saved register
        case R_A0: return "R_A0"; // 10, Function arguments/return values
        case R_A1: return "R_A1"; // 11, Function arguments/return values
        case R_A2: return "R_A2"; // 12, Function arguments
        case R_A3: return "R_A3"; // 13, Function arguments
        case R_A4: return "R_A4"; // 14, Function arguments
        case R_A5: return "R_A5"; // 15, Function arguments
        case R_A6: return "R_A6"; // 16, Function arguments
        case R_A7: return "R_A7"; // 17, Function arguments
        case R_S2: return "R_S2"; // 18, Saved registers
        case R_S3: return "R_S3"; // 19, Saved registers
        case R_S4: return "R_S4"; // 20, Saved registers
        case R_S5: return "R_S5"; // 21, Saved registers
        case R_S6: return "R_S6"; // 22, Saved registers
        case R_S7: return "R_S7"; // 23, Saved registers
        case R_S8: return "R_S8"; // 24, Saved registers
        case R_S9: return "R_S9"; // 25, Saved registers
        case R_S10: return "R_S10"; // 26, Saved registers
        case R_S11: return "R_S11"; // 27, Saved registers
        case R_T3: return "R_T3"; // 28, Temporary
        case R_T4: return "R_T4"; // 29, Temporary
        case R_T5: return "R_T5"; // 30, Temporary
        case R_T6: return "R_T6"; // 31, Temporary
  
        default: return "R_UNDEFINED_REGISTER";
    }
}