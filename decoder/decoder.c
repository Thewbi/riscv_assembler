#include "decoder.h"

void decode(uint32_t data, asm_line_t* asm_line) {

    //printf("decode\n");

    uint8_t instruction = data & 0b1111111;

    switch (instruction) {

        case 0b0110011: // ADD
            //printf("decode - 0b0110011\n");
            decode_r_type(data, asm_line);
            break;

        case 0b0010011: // ADDI, SRLI
            //printf("decode - 0b0010011\n");
            decode_i_type(data, asm_line);
            break;

        case 0b1100011: // BEQ
            //printf("decode - 0b1100011\n");
            decode_b_type(data, asm_line);
            break;

        default:
            printf("Unknown instruction!\n");
            break;

    }

}

void decode_r_type(uint32_t data, asm_line_t* asm_line) {

    //printf("decode_r_type\n");

    uint8_t rd = (data >> 7) & 0b11111;
    uint8_t funct3 = (data >> (7+5)) & 0b111;
    uint8_t rs1 = (data >> (7+5+3)) & 0b11111;
    uint8_t rs2 = (data >> (7+5+3+5)) & 0b11111;
    uint8_t funct7 = (data >> (7+5+3+5+5)) & 0b1111111;

    asm_line->reg_rd = decode_register(rd);
    asm_line->reg_rs1 = decode_register(rs1);
    asm_line->reg_rs2 = decode_register(rs2);

    switch (funct7) {

        case 0b0000000:
            switch (funct3) {
                case 0b000:
                    asm_line->instruction = I_ADD;
                    break;
            }

        case 0b0010011:
            switch (funct3) {

                case 0b000:
                    asm_line->instruction = I_ADD;
                    break;

                
            }
        break;
    }
}

void decode_i_type(uint32_t data, asm_line_t* asm_line) {

    //printf("decode_i_type\n");

    uint8_t rd = (data >> 7) & 0b11111;
    uint8_t funct3 = (data >> (7+5)) & 0b111;
    uint8_t rs1 = (data >> (7+5+3)) & 0b11111;
    uint16_t imm = (data >> (7+5+3+5)) & 0b111111111111;

    asm_line->reg_rd = decode_register(rd);
    asm_line->reg_rs1 = decode_register(rs1);
    asm_line->imm = imm;

    switch (funct3) {

        case 0b000: // I_ADDI
            asm_line->instruction = I_ADDI;
            break;

        case 0b101: // SRLI
            //printf("decode_i_type SRLI\n");
            asm_line->instruction = I_SRLI;
            break;

        case 0b001: // SLLI
            //printf("decode_i_type SLLI\n");
            asm_line->instruction = I_SLLI;
            break;
    }
}

void decode_b_type(uint32_t data, asm_line_t* asm_line) {

    //printf("decode_b_type\n");

    uint8_t funct3 = (data >> (7+5)) & 0b111;
    uint8_t rs1 = (data >> (7+5+3)) & 0b11111;
    uint8_t rs2 = (data >> (7+5+3+5)) & 0b11111;
    uint16_t imm11 = (data >> (7)) & 0b1;
    uint16_t imm4_1 = (data >> (8)) & 0b1111;
    uint16_t imm10_5 = (data >> (25)) & 0b111111;
    uint16_t imm12 = (data >> (31)) & 0b1;

    asm_line->reg_rs1 = decode_register(rs1);
    asm_line->reg_rs2 = decode_register(rs2);
    asm_line->imm = (imm12 << 11) | (imm11 << 0) | (imm10_5 << 5) | (imm4_1 << 1);

    switch (funct3) {

        case 0b000: // BEQ
            //printf("decode_i_type BEQ\n");
            asm_line->instruction = I_BEQ;
            break;

    }
}

enum register_ decode_register(uint8_t data) {

    switch (data) {

        // 0, Hard-wired zero
        case 0b00000:
            return R_ZERO;

        case 0b00001: // 1, Return address
            return R_RA;

        case 0b00010: // 2, Stack pointer
            return R_SP;

        case 0b00011: // 3, Global pointer
            return R_GP;

        case 0b00100: // 4, Thread pointer
            return R_TP;

        // ABI Name: t0, Register: x5 - encoded: 0101 (= 5 decimal) 
        case 0b00101: // 5, Temporary/alternate link register
            return R_T0;

        case 0b00110: // 6, Temporary
            return R_T1;

        case 0b00111: // 7, Temporary
            return R_T2;

        case 0b01000: // 8, Saved register/frame pointer
            return R_S0;

        case 0b01001: // 9, Saved register
            return R_S1;

        // ABI Name: a0, Register: x10 - encoded: 1010 (= 10 decimal)
        case 0b01010: // 10, Function arguments/return values
             return R_A0;

        case 0b01011: // 11, Function arguments/return values
            return R_A1;

        case 0b01100: // 12, Function arguments
            return R_A2;

        case 0b01101: // 13, Function arguments
            return R_A3;

        case 0b01110: // 14, Function arguments
            return R_A4;

        case 0b01111: // 15, Function arguments
            return R_A5;

        case 0b10000: // 16, Function arguments
            return R_A6;

        case 0b10001: // 17, Function arguments
            return R_A7;

        case 0b10010: // 18, Saved registers
            return R_S2;

        case 0b10011: // 19, Saved registers
            return R_S3;

        case 0b10100: // 20, Saved registers
            return R_S4;

        case 0b10101: // 21, Saved registers
            return R_S5;

        case 0b10110: // 22, Saved registers
            return R_S6;

        case 0b10111: // 23, Saved registers
            return R_S7;

        case 0b11000: // 24, Saved registers
            return R_S8;

        case 0b11001: // 25, Saved registers
            return R_S9;

        case 0b11010: // 26, Saved registers
            return R_S10;

        case 0b11011: // 27, Saved registers
            return R_S11;

        case 0b11100: // 28, Temporary
            return R_T3;

        case 0b11101: // 29, Temporary
            return R_T4;
            
        case 0b11110: // 30, Temporary
            return R_T5;

        case 0b11111: // 31, Temporary
            return R_T6;

        default:
            //printf("unknown register %d\n", data); 
            return R_UNDEFINED_REGISTER;
    }
}