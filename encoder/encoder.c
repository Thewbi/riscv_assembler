#include "encoder.h"

void encoder_callback(asm_line_t* asm_line) {

    printf("encoder_callback\n");

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

        case I_SW:
            encoded_asm_line = encode_sw(asm_line);
            break;

        default:
            printf("Unknown instruction!\n");
            return;
    }

    printf("encoder_callback 0x%08x\n", encoded_asm_line);

    reset_asm_line(asm_line);
}

uint32_t encode_add(asm_line_t* asm_line) {

    // printf("encode_add\n");

    // printf("asm_line->reg_rd %d\n", asm_line->reg_rd);
    // printf("asm_line->reg_rs1 %d\n", asm_line->reg_rs1);
    // printf("asm_line->reg_rs2 %d\n", asm_line->reg_rs2);

    uint8_t funct7 = 0b0000000;
    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0110011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);

    // printf("rd %d\n", rd);
    // printf("rs1 %d\n", rs1);
    // printf("rs2 %d\n", rs2);

    return encode_r_type(funct7, rs2, rs1, funct3, rd, opcode);
}

uint32_t encode_addi(asm_line_t* asm_line) {

    //printf("encode_addi\n");

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

void encode_call(asm_line_t* asm_line, uint32_t* output_buffer) {

    // auipc x6, offset[31:12] 
    // jalr x1, x6, offset[11:0]

    uint32_t data_0 = (asm_line->imm & 0xFFFFF000) >> 12;
    uint32_t data_1 = (asm_line->imm & 0xFFF);

    enum register_ free_temp_register = R_T1; // x6

    // aupic instruction (auipc x6, 0x0BFFF -> 0x0bfff317)
    uint8_t opcode = 0b0010111;
    uint8_t rd = encode_register(free_temp_register);
    uint32_t imm = data_0;
    printf("encode_aupic imm: %d\n", imm);

    uint32_t aupic_encoded = encode_u_type(imm, rd, opcode);
    printf("aupic_encoded: %08" PRIx32 "\n", aupic_encoded);

    output_buffer[0] = aupic_encoded;

    // 8. Take data_2 and create a jalr instruction. Use data_2 as the offset
    uint8_t funct3 = 0b000;
    opcode = 0b1100111;

    rd = encode_register(R_ZERO);
    uint8_t rs1 = encode_register(free_temp_register);
    imm = data_1;

    uint32_t jalr_encoded = encode_i_type(imm, rs1, funct3, rd, opcode);
    printf("jalr_encoded: %08" PRIx32 "\n", jalr_encoded);

    output_buffer[1] = jalr_encoded;
}

void encode_j(asm_line_t* asm_line, uint32_t* output_buffer) {

    // implemented using:
    // https://www.reddit.com/r/RISCV/comments/129qg6t/can_someone_pls_explain/?tl=de

    uint32_t data_0 = asm_line->imm;
    printf("data_0: %08" PRIx32 "\n", data_0);

    // 1. Take the value 0xBFFF00 and multiply it by 4 because it is the amount of instructions with 4 byte per instruction
    uint32_t data_1 = data_0 * 4;
    printf("data_1: %08" PRIx32 "\n", data_1);

    // 2. Take the lower 12 bits of data_1 (0xC00) = data_2
    uint32_t data_2 = data_1 & 0xFFF;
    printf("data_2: %08" PRIx32 "\n", data_2);

    // 3. interpret data_2 as a sign extended value:
    uint32_t data_3 = sign_extend_12_bit_to_uint32_t(data_2);
    printf("data_3: %08" PRIx32 "\n", data_3);

    uint32_t temp = (-1) * data_3;
    //uint32_t temp = 1024;
    printf("temp: %08" PRIx32 "\n", temp);

    // 4. Take this negative value (data_3), invert the sign and add it to the original value (data_1).
    uint32_t data_4 = data_1 + temp;
    printf("data_4: %08" PRIx32 "\n", data_4);

    // 5. Take only the upper 20 bits of data_4
    uint32_t data_5 = data_4 >> 12;
    printf("data_5: %08" PRIx32 "\n", data_5);

    // 6. Select a free temporary register (here: x5)
    enum register_ free_temp_register = R_T0; // x5
    printf("free_temp_register: %08" PRIx32 "\n", free_temp_register);

    // 7. Take data_5 and create an aupic instruction
    uint8_t opcode = 0b0010111;
    uint8_t rd = encode_register(free_temp_register);
    uint32_t imm = data_5;
    printf("encode_aupic imm: %d\n", imm);

    uint32_t aupic_encoded = encode_u_type(imm, rd, opcode);
    printf("aupic_encoded: %08" PRIx32 "\n", aupic_encoded);

    output_buffer[0] = aupic_encoded;

    // 8. Take data_2 and create a jalr instruction. Use data_2 as the offset
    uint8_t funct3 = 0b000;
    opcode = 0b1100111;

    rd = encode_register(R_ZERO);
    uint8_t rs1 = encode_register(free_temp_register);
    imm = data_2;

    uint32_t jalr_encoded = encode_i_type(imm, rs1, funct3, rd, opcode);
    printf("jalr_encoded: %08" PRIx32 "\n", jalr_encoded);

    output_buffer[1] = jalr_encoded;
}

uint32_t encode_lw(asm_line_t* asm_line) {

    // printf("encode_sw\n");

    // printf("asm_line->reg_rs1 %d\n", asm_line->reg_rs1);
    // printf("asm_line->reg_rs2 %d\n", asm_line->reg_rs2);
    // printf("asm_line->imm %d\n", asm_line->imm);

    // printf("asm_line->offset_0_used %d\n", asm_line->offset_0_used);
    // printf("asm_line->offset_0 %d\n", asm_line->offset_0);
    
    // printf("asm_line->offset_1_used %d\n", asm_line->offset_1_used);
    // printf("asm_line->offset_1 %d\n", asm_line->offset_1);

    // printf("asm_line->offset_2_used %d\n", asm_line->offset_2_used);
    // printf("asm_line->offset_2 %d\n", asm_line->offset_2);

    uint8_t funct3 = 0b010;
    uint8_t opcode = 0b0000011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rd = encode_register(asm_line->reg_rd);
    uint16_t imm = asm_line->offset_1;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_lui(asm_line_t* asm_line) {

    uint8_t opcode = 0b0110111;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint32_t imm = asm_line->imm;

    //printf("encode_lui asm_line->imm: %d\n", imm);

    return encode_u_type(imm, rd, opcode);
}

// https://stackoverflow.com/questions/56781564/how-to-load-an-immediate-number-to-a-register-in-rv32i-base-instruction-set
//
// li is a pseudo instruction. Here it is implemented by a LUI and ADDI instruction
//
// 11011110101011011100
//
// DEADBEEF = 3735928559 (data_0)
// 000DEADB (data_1)
//
// 000DEADC = data_1 + 1 = 912092 
// 000DEADC
// DEADC000 = 3735928832 (data_2)
//
// data_3 = data_0 - data_2 = DEADBEEF - DEADC000 = 0xFFFFFFFFFFFFFEEF => 0xEEF
//                          = 3735928559 - 3735928832 = -273
//
// EEF + 1 = EF0
//
// lui     a0, 0xdeadc   0b11011110101011011100
// addi    a0, a0, -273  0b111111111111111111111111111111111111111111111111 1111 1110 1110 1111
//
//                      0xDEADC
//                      0xFFFFFFFFFFFFFEEF
//                      
//                      B
//                      1011
//                    
//                      0xD    E    A    D    B    0    0    0    
//                        1101 1110 1010 1101 1011 0000 0000 0000
//                       
//                                           0    E    E    F
//                                           0000 1110 1110 1111
//                                                 
//                                                 
//                                                 take the 32 bit value (data_0)
//                                                 split it into a 20 bit (data_1) and a twelve bit part (is ignored)
//                                                 the 20 bit part is incremented by 1, then shifted left by 12 bits to get (data_2)
//                                                 form a "lui rd, data2" command
//                                                 the twelve bit part (data_3) created by data_3 = data_0 - data_2
//                                                 Only the lower twelve bits of data_3 are relevant!
//                                                 data_4 = lower_twelve_bits(data_3)
//                                                 form a "addi rd, rd, data_4" command
//
void encode_li(asm_line_t* asm_line, uint32_t* output_buffer) {

    //printf("asm_line->imm: 0x%" PRIx64 "\n", asm_line->imm);
    //printf("asm_line->imm: %08" PRIx32 "\n", asm_line->imm);

    // take the 32 bit value (data_0)
    uint32_t data_0 = asm_line->imm;

    // split it into a 20 bit (data_1) and a twelve bit part (is ignored)
    uint32_t data_1 = ((data_0 & 0b11111111111111111111000000000000) >> 12);

    // the 20 bit part is incremented by 1, (then shifted left by 12 bits to get (data_2))
    data_1 = data_1 + 1;

    //printf("data_2: %08" PRIx32 "\n", data_1);

    //
    // lui
    //

    uint8_t opcode = 0b0110111;
    uint8_t rd = encode_register(asm_line->reg_rd);
    uint32_t imm = data_1;
    //printf("encode_lui asm_line->imm: %d\n", imm);
    uint32_t lui_encoded = encode_u_type(imm, rd, opcode);
    //printf("lui_encoded: %08" PRIx32 "\n", lui_encoded);

    output_buffer[0] = lui_encoded;

    //
    // addi
    //

    uint32_t data_2 = data_1 << 12;
    uint32_t data_3 = (data_0 - data_2) & 0xFFF;
    //printf("data_3: %08" PRIx32 "\n", data_3);

    uint8_t funct3 = 0b000;
    opcode = 0b0010011;

    rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rd);
    imm = data_3;

    uint32_t addi_encoded = encode_i_type(imm, rs1, funct3, rd, opcode);
    //printf("addi_encoded: %08" PRIx32 "\n", addi_encoded);

    output_buffer[1] = addi_encoded;
}

uint32_t encode_mul(asm_line_t* asm_line) {

    uint8_t funct7 = 0b0000001;
    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0110011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);
    uint8_t rd = encode_register(asm_line->reg_rd);

    return encode_r_type(funct7, rs2, rs1, funct3, rd, opcode);
}

// mv (move) is a pseudoinstruction. It is implemented using: 
// mv rd, rs --> addi rd, rs, 0
// mv a0, a5 --> addi a0, a5, 0
uint32_t encode_mv(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0010011;
    uint16_t imm = 0;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rd = encode_register(asm_line->reg_rd);

    return encode_i_type(imm, rs1, funct3, rd, opcode);
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

// https://luplab.gitlab.io/rvcodecjs/#q=sw++++++ra,28(sp)&abi=false&isa=AUTO
uint32_t encode_sw(asm_line_t* asm_line) {

    // printf("encode_sw\n");

    // printf("asm_line->reg_rs1 %d\n", asm_line->reg_rs1);
    // printf("asm_line->reg_rs2 %d\n", asm_line->reg_rs2);
    // printf("asm_line->imm %d\n", asm_line->imm);

    // printf("asm_line->offset_0_used %d\n", asm_line->offset_0_used);
    // printf("asm_line->offset_0 %d\n", asm_line->offset_0);
    
    // printf("asm_line->offset_1_used %d\n", asm_line->offset_1_used);
    // printf("asm_line->offset_1 %d\n", asm_line->offset_1);

    // printf("asm_line->offset_2_used %d\n", asm_line->offset_2_used);
    // printf("asm_line->offset_2 %d\n", asm_line->offset_2);

    uint8_t funct3 = 0b010;
    uint8_t opcode = 0b0100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);
    uint16_t imm = asm_line->offset_1;

    return encode_s_type(imm, rs1, rs2, funct3, opcode);
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
    // printf("encode_b_type rs2: %d \n", rs2);
    // printf("encode_b_type funct3: %d \n", funct3);
    // printf("encode_b_type opcode: %d \n", opcode);

    return ((opcode & 0b1111111) << 0) |
           ((imm & 0b11111) << 7) |
           ((funct3 & 0b111) << (7+5)) |
           ((rs1 & 0b11111) << (7+5+3)) |
           ((rs2 & 0b11111) << (7+5+3+5)) |
           ((imm & 0b111111100000) << (7+5+3+5+5));
}

uint32_t encode_s_type(uint16_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode) {
    return encode_b_type(imm, rs2, rs1, funct3, opcode);
}

uint32_t encode_u_type(uint32_t imm, uint8_t rd, uint8_t opcode) {

    //printf("encode_u_type opcode: %d \n", opcode);
    //printf("encode_u_type rd: %d \n", rd);
    //printf("encode_u_type imm: %d \n", imm);
    //printf("encode_u_type imm: %08" PRIx32 "\n", imm);

    return ((opcode & 0b1111111) << 0) |
           ((rd & 0b11111) << 7) |
           ((imm & 0b11111111111111111111) << (7+5));
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