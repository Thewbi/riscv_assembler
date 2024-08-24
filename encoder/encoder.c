#include "encoder.h"

void encoder_callback(asm_line_t* asm_line) {

    uint32_t encoded_asm_line = 0;

    switch (asm_line->instruction) {

        case I_ADD:
            encoded_asm_line = encode_add(asm_line);
            break;

        case I_ADDI:
            encoded_asm_line = encode_addi(asm_line);
            break;

        case I_SRLI:
            encoded_asm_line = encode_srli(asm_line);
            break;

        case I_SLLI:
            encoded_asm_line = encode_slli(asm_line);
            break;

        default:
            printf("Unknown instruction!\n");
            return;
    }

    reset_asm_line(asm_line);
}

uint32_t encode_add(asm_line_t* asm_line) {

    uint8_t funct7 = 0b0000000;
    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0110011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);

    return encode_r_type(funct7, rs2, rs1, funct3, rd, opcode);
}

uint32_t encode_addi(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0010011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint16_t imm = asm_line->imm;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_beq(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b1100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);
    uint16_t imm = asm_line->imm;

    return encode_b_type(imm, rs2, rs1, funct3, opcode);
}

uint32_t encode_srli(asm_line_t* asm_line) {

    //printf("encode_srli\n");

    uint8_t funct3 = 0b101;
    uint8_t opcode = 0b0010011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint16_t imm = asm_line->imm;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_slli(asm_line_t* asm_line) {

    //printf("encode_slli\n");

    uint8_t funct3 = 0b001;
    uint8_t opcode = 0b0010011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint16_t imm = asm_line->imm;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_r_type(uint8_t funct7, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode) {

    // printf("encode_r_type funct7: %d \n", funct7);
    // printf("encode_r_type rs2: %d \n", rs2);
    // printf("encode_r_type rs1: %d \n", rs1);
    // printf("encode_r_type funct3: %d \n", funct3);
    // printf("encode_r_type rd: %d \n", rd);
    // printf("encode_r_type opcode: %d \n", opcode);

    return ((opcode & 0b1111111) << 0) |
           ((rd & 0b11111) << 7) |
           ((funct3 & 0b111) << (7+5)) |
           ((rs1 & 0b11111) << (7+5+3)) |
           ((rs2 & 0b11111) << (7+5+3+5)) |
           ((funct7 & 0b1111111) << (7+5+3+5+5));
}

uint32_t encode_i_type(uint16_t imm, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode) {

    // printf("encode_i_type imm: %d \n", imm);
    // printf("encode_i_type rs1: %d \n", rs1);
    // printf("encode_i_type funct3: %d \n", funct3);
    // printf("encode_i_type rd: %d \n", rd);
    // printf("encode_i_type opcode: %d \n", opcode);

    return ((opcode & 0b1111111) << 0) |
           ((rd & 0b11111) << 7) |
           ((funct3 & 0b111) << (7+5)) |
           ((rs1 & 0b11111) << (7+5+3)) |
           ((imm & 0b111111111111) << (7+5+3+5));
}

uint32_t encode_b_type(uint16_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode) {

    // printf("encode_b_type imm: %d \n", imm);
    // printf("encode_b_type rs1: %d \n", rs1);
    // printf("encode_b_type funct3: %d \n", funct3);
    // printf("encode_b_type rd: %d \n", rd);
    // printf("encode_b_type opcode: %d \n", opcode);

    return ((opcode & 0b1111111) << 0) |
           ((imm & 0b11111) << 7) |
           ((funct3 & 0b111) << (7+5)) |
           ((rs1 & 0b11111) << (7+5+3)) |
           ((rs2 & 0b11111) << (7+5+3+5)) |
           ((imm & 0b111111100000) << (7+5+3+5+5));
}

uint8_t encode_register(enum register_ data) {

    switch (data) {

        // 0, Hard-wired zero
        case R_ZERO:
            return 0b00000;

        case R_RA: // 1, Return address
            return 0b00001;

        case R_SP: // 2, Stack pointer
            return 0b00010;

        case R_GP: // 3, Global pointer
            return 0b00011;

        case R_TP: // 4, Thread pointer
            return 0b00100;

        // ABI Name: t0, Register: x5 - encoded: 0101 (= 5 decimal) 
        case R_T0: // 5, Temporary/alternate link register
            return 0b00101;

        case R_T1: // 6, Temporary
            return 0b00110;

        case R_T2: // 7, Temporary
            return 0b00111;

        case R_S0: // 8, Saved register/frame pointer
            return 0b01000;

        case R_S1: // 9, Saved register
            return 0b01001;

        // ABI Name: a0, Register: x10 - encoded: 1010 (= 10 decimal)
        case R_A0: // 10, Function arguments/return values
             return 0b01010;

        case R_A1: // 11, Function arguments/return values
            return 0b01011;

        case R_A2: // 12, Function arguments
            return 0b01100;

        case R_A3: // 13, Function arguments
            return 0b01101;

        case R_A4: // 14, Function arguments
            return 0b01110;

        case R_A5: // 15, Function arguments
            return 0b01111;

        case R_A6: // 16, Function arguments
            return 0b10000;

        case R_A7: // 17, Function arguments
            return 0b10001;

        case R_S2: // 18, Saved registers
            return 0b10010;

        case R_S3: // 19, Saved registers
            return 0b10011;

        case R_S4: // 20, Saved registers
            return 0b10100;

        case R_S5: // 21, Saved registers
            return 0b10101;

        case R_S6: // 22, Saved registers
            return 0b10110;

        case R_S7: // 23, Saved registers
            return 0b10111;

        case R_S8: // 24, Saved registers
            return 0b11000;

        case R_S9: // 25, Saved registers
            return 0b11001;

        case R_S10: // 26, Saved registers
            return 0b11010;

        case R_S11: // 27, Saved registers
            return 0b11011;

        case R_T3: // 28, Temporary
            return 0b11100;

        case R_T4: // 29, Temporary
            return 0b11101;

        case R_T5: // 30, Temporary
            return 0b11110;

        case R_T6: // 31, Temporary
            return 0b11111;

        default:
            printf("unknown register %d\n", data); 
            return 0;
    }
}