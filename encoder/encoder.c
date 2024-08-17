#include "encoder.h"

void encoder_callback(asm_line_t* asm_line) {

    printf("encoder_callback\n");

    uint32_t encoded_asm_line = 0;

    switch (asm_line->instruction) {

        case I_ADD:
            encoded_asm_line = encode_add(asm_line);
            break;

        default:
            printf("Unknown instruction!\n");
            return;
    }

    printf("encoded_asm_line %d\n", encoded_asm_line);
    printf("%" PRIu32 "\n", encoded_asm_line);

    reset_asm_line(asm_line);
}

uint32_t encode_add(asm_line_t* asm_line) {

    printf("encode_add\n");

    uint8_t funct7 = 0b0000000;
    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0110011;

    printf("encode_add %d %d %d\n", asm_line->reg_1, asm_line->reg_2, asm_line->reg_3);

    uint8_t rd = encode_register(asm_line->reg_1);
    uint8_t rs1 = encode_register(asm_line->reg_2);
    uint8_t rs2 = encode_register(asm_line->reg_3);

    return encode_r_type(funct7, rs2, rs1, funct3, rd, opcode);
}

uint32_t encode_r_type(uint8_t funct7, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode) {

    printf("encode_r_type funct7: %d \n", funct7);
    printf("encode_r_type rs2: %d \n", rs2);
    printf("encode_r_type rs1: %d \n", rs1);
    printf("encode_r_type funct3: %d \n", funct3);
    printf("encode_r_type rd: %d \n", rd);
    printf("encode_r_type opcode: %d \n", opcode);

    return ((opcode & 0b1111111) << 0) |
           ((rd & 0b11111) << 7) |
           ((funct3 & 0b111) << (7+5)) |
           ((rs1 & 0b11111) << (7+5+3)) |
           ((rs2 & 0b11111) << (7+5+3+5)) |
           ((funct7 & 0b1111111) << (7+5+3+5+5));
}

uint8_t encode_register(enum register_ data) {

    switch (data) {

        case R_ZERO:
            printf("aaaabbb\n");
            return 0b00101;

        // ABI Name: t0, Register: x5 - encoded: 0101 (= 5 decimal) 
        case R_T0:
            printf("aaaabbb\n");
            return 0b00101;

        // ABI Name: a0, Register: x10 - encoded: 1010 (= 10 decimal)
        //case R_A0:
        //    return 0b01010;

        default:
            printf("unknown register %d\n", data); 
            return 0;
    }
}