#include "encoder.h"

int asm_line_array_index = 0;
asm_line_t asm_line_array[100];



// int32_t compute_relative_offset(int32_t imm, int32_t instruction_index) {
//     return (imm - ((instruction_index + 0) * 4));
// }

// Whenever the parser reduces a rule for a asm_line, it is performing an action.
// Inside this action, it calls the fp_emit function pointer.
// This method "encoder_callback()" is registered as fp_emit function pointer
// and therefore is called whenever a asm_line is reduced.
//
// It copies the working asm_line into the array of asm_lines and resets
// the working asm_line so it can be reused in the next line parse iteration.
void encoder_callback(asm_line_t* asm_line) {

    copy_asm_line(&asm_line_array[asm_line_array_index], asm_line);
    asm_line_array[asm_line_array_index].used = 1;

    asm_line_array_index++;

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

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0010011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    int32_t imm = retrieve_immediate_part(asm_line);

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_addiw(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0011011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    int32_t imm = retrieve_immediate_part(asm_line);

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_auipc(asm_line_t* asm_line) {

    uint8_t opcode = 0b0010111;

    uint8_t rd = encode_register(asm_line->reg_rd);
    int32_t imm = retrieve_immediate_part(asm_line);

    return encode_u_type(imm, rd, opcode);
}

uint32_t encode_beq(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b1100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);
    int32_t imm = retrieve_immediate_part(asm_line);

    //int32_t relative_offset = imm - ((asm_line->instruction_index + 0) * 4);
    int32_t relative_offset = imm;

    return encode_b_type(relative_offset, rs2, rs1, funct3, opcode);
}

uint32_t encode_bge(asm_line_t* asm_line) {

    uint8_t funct3 = 0b101;
    uint8_t opcode = 0b1100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);
    int32_t imm = retrieve_immediate_part(asm_line);

    //int32_t relative_offset = imm - ((asm_line->instruction_index + 0) * 4);
    int32_t relative_offset = imm;

    return encode_b_type(relative_offset, rs2, rs1, funct3, opcode);
}

uint32_t encode_bne(asm_line_t* asm_line) {

    uint8_t funct3 = 0b001;
    uint8_t opcode = 0b1100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);

    int32_t imm = retrieve_immediate_part(asm_line);

    //int32_t relative_offset = imm - ((asm_line->instruction_index + 0) * 4);
    //uint32_t relative_offset = sign_extend_uint16_t(imm);
    uint16_t relative_offset = imm;
    //int32_t relative_offset = imm;

    // relative_offset = relative_offset >> 1;
    // relative_offset |= 0b1000000000000000;

    // uint16_t test = relative_offset;
    // for (int i = 15; i >= 0; --i) {
    //     printf("%" PRIu32, test >> i & 1);
    // }
    // printf("\n");

    //1111111111111110

    return encode_b_type(relative_offset, rs2, rs1, funct3, opcode);
}

uint32_t encode_blt(asm_line_t* asm_line) {

    uint8_t funct3 = 0b100;
    uint8_t opcode = 0b1100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);

    int32_t imm = retrieve_immediate_part(asm_line);

    //int32_t relative_offset = imm - ((asm_line->instruction_index + 0) * 4);
    int32_t relative_offset = imm;

    return encode_b_type(relative_offset, rs2, rs1, funct3, opcode);
}

uint32_t encode_bnez(asm_line_t* asm_line) {

    uint8_t funct3 = 0b001;
    uint8_t opcode = 0b1100011;

    uint8_t rs1 = encode_register(asm_line->reg_rd);
    uint8_t rs2 = encode_register(R_ZERO);
    int64_t imm = asm_line->offset_1_expression->int_val;

    return encode_b_type(imm, rs2, rs1, funct3, opcode);
}

void encode_call(asm_line_t* asm_line, uint32_t* output_buffer) {

    // call offset ->
    //  auipc x6, offset[31:12]
    //  jalr x1, x6, offset[11:0]

    uint32_t imm_int_val = asm_line->offset_0_expression->int_val;

    uint32_t data_0 = (imm_int_val & 0xFFFFF000) >> 12;
    uint32_t data_1 = (imm_int_val & 0xFFF);

    // TODO: search for a register that is really free
    enum register_ free_temp_register = R_T1; // x6

    //
    // auipc (auipc rd, imm  # rd = pc + imm << 12)
    //

    // aupic instruction (auipc x6, 0x0BFFF -> 0x0bfff317)
    uint8_t opcode = 0b0010111;
    uint8_t rd = encode_register(free_temp_register);
    uint32_t imm = data_0;
    //printf("encode_aupic imm: %d\n", imm);

    uint32_t aupic_encoded = encode_u_type(imm, rd, opcode);
    //printf("aupic_encoded: %08" PRIx32 "\n", aupic_encoded);

    output_buffer[0] = aupic_encoded;

    //
    // jalr
    //

    // 8. Take data_2 and create a jalr instruction. Use data_2 as the offset
    uint8_t funct3 = 0b000;
    opcode = 0b1100111;

    rd = encode_register(R_ZERO);
    uint8_t rs1 = encode_register(free_temp_register);
    imm = data_1;

    uint32_t jalr_encoded = encode_i_type(imm, rs1, funct3, rd, opcode);
    //printf("jalr_encoded: %08" PRIx32 "\n", jalr_encoded);

    output_buffer[1] = jalr_encoded;
}

// j 0xBFFF00
void encode_j(asm_line_t* asm_line, uint32_t* output_buffer) {

    // implemented using:
    // https://www.reddit.com/r/RISCV/comments/129qg6t/can_someone_pls_explain/?tl=de

    //uint32_t data_0 = asm_line->imm;
    //uint32_t data_0 = sign_extend_20_bit_to_uint32_t(asm_line->offset_0_expression->int_val);
    uint32_t data_0 = asm_line->offset_0_expression->int_val;
    //printf("data_0: %08" PRIx32 "\n", data_0);

    // 1. Take the value 0xBFFF00 and multiply it by 4 because it is the amount of instructions with 4 byte per instruction
    uint32_t data_1 = data_0 * 4;
    //printf("data_1: %08" PRIx32 "\n", data_1);

    // 2. Take the lower 12 bits of data_1 (0xC00) = data_2
    uint32_t data_2 = data_1 & 0xFFF;
    //printf("data_2: %08" PRIx32 "\n", data_2);

    // 3. interpret data_2 as a sign extended value:
    uint32_t data_3 = sign_extend_12_bit_to_uint32_t(data_2);
    //printf("data_3: %08" PRIx32 "\n", data_3);

    uint32_t temp = (-1) * data_3;
    //uint32_t temp = 1024;
    //printf("temp: %08" PRIx32 "\n", temp);

    // 4. Take this negative value (data_3), invert the sign and add it to the original value (data_1).
    uint32_t data_4 = data_1 + temp;
    //printf("data_4: %08" PRIx32 "\n", data_4);

    // 5. Take only the upper 20 bits of data_4
    uint32_t data_5 = data_4 >> 12;
    //printf("data_5: %08" PRIx32 "\n", data_5);

    // 6. Select a free temporary register (here: x5)
    enum register_ free_temp_register = R_T0; // x5
    //printf("free_temp_register: %08" PRIx32 "\n", free_temp_register);

    // 7. Take data_5 and create an aupic instruction
    uint8_t opcode = 0b0010111;
    uint8_t rd = encode_register(free_temp_register);
    uint32_t imm = data_5;
    //printf("encode_aupic imm: %d\n", imm);

    uint32_t aupic_encoded = encode_u_type(imm, rd, opcode);
    //printf("aupic_encoded: %08" PRIx32 "\n", aupic_encoded);

    output_buffer[0] = aupic_encoded;

    // 8. Take data_2 and create a jalr instruction. Use data_2 as the offset
    uint8_t funct3 = 0b000;
    opcode = 0b1100111;

    rd = encode_register(R_ZERO);
    uint8_t rs1 = encode_register(free_temp_register);
    imm = data_2;

    //int32_t relative_offset = imm - ((asm_line->instruction_index + 1) * 4);

    uint32_t jalr_encoded = encode_i_type(imm, rs1, funct3, rd, opcode);

    // DEBUG
    //printf("jalr_encoded: %08" PRIx32 "\n", jalr_encoded);

    output_buffer[1] = jalr_encoded;
}

uint32_t encode_jal(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b1101111;

    uint8_t rd = encode_register(asm_line->reg_rd);
    int32_t imm = retrieve_immediate_part(asm_line);

    //int32_t relative_offset = imm - ((asm_line->instruction_index + 1) * 4);
    //int32_t relative_offset = compute_relative_offset(imm, asm_line->instruction_index);
    int32_t relative_offset = imm;

    uint32_t result = encode_j_type(relative_offset, rd, opcode);

    //printf("encode_jal: relative_offset: %d, result: %08" PRIx32 "\n", relative_offset, result);

    return result;
}

uint32_t encode_jalr(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b1100111;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    int32_t imm = retrieve_immediate_part(asm_line);

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_lb(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0000011;

    if (asm_line->reg_rs1 == R_UNDEFINED_REGISTER) {
        asm_line->reg_rs1 = R_ZERO;
    }

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rd = encode_register(asm_line->reg_rd);
    //int64_t imm = asm_line->offset_1_expression->int_val;
    int64_t imm = asm_line->offset_1;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_lh(asm_line_t* asm_line) {

    uint8_t funct3 = 0b001;
    uint8_t opcode = 0b0000011;

    if (asm_line->reg_rs1 == R_UNDEFINED_REGISTER) {
        asm_line->reg_rs1 = R_ZERO;
    }

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rd = encode_register(asm_line->reg_rd);
    //int64_t imm = asm_line->offset_1_expression->int_val;
    int64_t imm = asm_line->offset_1;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_lw(asm_line_t* asm_line) {

    uint8_t funct3 = 0b010;
    uint8_t opcode = 0b0000011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rd = encode_register(asm_line->reg_rd);
    int32_t imm = asm_line->offset_1;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_ld(asm_line_t* asm_line) {

    uint8_t funct3 = 0b011;
    uint8_t opcode = 0b0000011;

    if (asm_line->reg_rs1 == R_UNDEFINED_REGISTER) {
        asm_line->reg_rs1 = R_ZERO;
    }

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rd = encode_register(asm_line->reg_rd);
    //uint16_t imm = asm_line->offset_1_expression->int_val;
    uint16_t imm = asm_line->offset_1;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_sb(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b0100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);
    uint16_t imm = asm_line->offset_1;

    return encode_s_type(imm, rs2, rs1, funct3, opcode);
}

uint32_t encode_sh(asm_line_t* asm_line) {

    uint8_t funct3 = 0b001;
    uint8_t opcode = 0b0100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);
    uint16_t imm = asm_line->offset_1;

    return encode_s_type(imm, rs2, rs1, funct3, opcode);
}

// https://luplab.gitlab.io/rvcodecjs/#q=sw++++++ra,28(sp)&abi=false&isa=AUTO
uint32_t encode_sw(asm_line_t* asm_line) {

    uint8_t funct3 = 0b010;
    uint8_t opcode = 0b0100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);

    uint16_t imm = retrieve_immediate_part(asm_line);
    //uint16_t imm = asm_line->offset_1;

    return encode_s_type(imm, rs2, rs1, funct3, opcode);
}

uint32_t encode_sd(asm_line_t* asm_line) {

    uint8_t funct3 = 0b011;
    uint8_t opcode = 0b0100011;

    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    uint8_t rs2 = encode_register(asm_line->reg_rs2);
    uint16_t imm = asm_line->offset_1;

    return encode_s_type(imm, rs2, rs1, funct3, opcode);
}

// https://luplab.gitlab.io/rvcodecjs/#q=0xdeadc537&abi=false&isa=AUTO
uint32_t encode_lui(asm_line_t* asm_line) {

    //print_asm_line(asm_line);

    uint8_t opcode = 0b0110111;

    uint8_t rd = encode_register(asm_line->reg_rd);
    //uint32_t imm = asm_line->imm;

    //uint16_t imm = asm_line->offset_0_expression->int_val;
    int32_t imm = retrieve_immediate_part(asm_line);

    //uint16_t imm = asm_line->offset_2_expression->int_val;

    //printf("encode_lui asm_line->imm: %d\n", imm);

    return encode_u_type(imm, rd, opcode);
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

uint32_t encode_ret(asm_line_t* asm_line) {

    uint8_t funct3 = 0b000;
    uint8_t opcode = 0b1100111;
    uint16_t imm = 0;

    uint8_t rs1 = encode_register(R_RA);
    uint8_t rd = encode_register(R_ZERO);

    // encode jalr (https://luplab.gitlab.io/rvcodecjs/#q=jalr+x0,+0(x1)&abi=false&isa=AUTO)
    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_srli(asm_line_t* asm_line) {

    //printf("encode_srli\n");

    uint8_t funct3 = 0b101;
    uint8_t opcode = 0b0010011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    //uint16_t imm = asm_line->imm;
    uint16_t imm = asm_line->offset_2_expression->int_val;

    return encode_i_type(imm, rs1, funct3, rd, opcode);
}

uint32_t encode_slli(asm_line_t* asm_line) {

    //printf("encode_slli\n");

    uint8_t funct3 = 0b001;
    uint8_t opcode = 0b0010011;

    uint8_t rd = encode_register(asm_line->reg_rd);
    uint8_t rs1 = encode_register(asm_line->reg_rs1);
    //uint16_t imm = asm_line->imm;
    uint16_t imm = asm_line->offset_2_expression->int_val;

    uint32_t result = encode_i_type(imm, rs1, funct3, rd, opcode);

    //printf("encode_slli result: %d\n", result);

    return result;
}

// funct7 rs2 rs1 funct3 rd
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

// imm[11:0] rs1 funct3 rd
uint32_t encode_i_type(uint16_t imm, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode) {

    // printf("encode_i_type imm: %d \n", imm);
    // printf("encode_i_type rs1: %d \n", rs1);
    // printf("encode_i_type funct3: %d \n", funct3);
    // printf("encode_i_type rd: %d \n", rd);
    // printf("encode_i_type opcode: %d \n", opcode);

    uint32_t result = ((opcode & 0b1111111) << 0) |
           ((rd & 0b11111) << 7) |
           ((funct3 & 0b111) << (7+5)) |
           ((rs1 & 0b11111) << (7+5+3)) |
           ((imm & 0b111111111111) << (7+5+3+5));

    return result;
}

// imm[11:5] rs2 rs1 funct3 imm[4:0]
uint32_t encode_s_type(uint16_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode) {

    uint32_t imm_4_0 = (imm >> 0) & 0b11111;
    uint32_t imm_11_5 = (imm >> 5) & 0b1111111;

    uint32_t result = ((opcode & 0b1111111) << 0) |
           ((imm_4_0) << 7) |
           ((funct3 & 0b111) << (7+5)) |
           ((rs1 & 0b11111) << (7+5+3)) |
           ((rs2 & 0b11111) << (7+5+3+5)) |
           ((imm_11_5 & 0b1111111) << (7+5+3+5+5));

    // uint32_t test = result;
    // for (int i = 31; i >= 0; --i) {
    //     printf("%" PRIu32, test >> i & 1);
    // }
    // printf("\n");

    return result;
}

// imm[12] imm[10:5] rs2 rs1 funct3 imm[4:1] imm[11] opcode
uint32_t encode_b_type(uint16_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode) {

    // printf("encode_b_type imm: %d \n", imm);
    // printf("encode_b_type rs1: %d \n", rs1);
    // printf("encode_b_type rs2: %d \n", rs2);
    // printf("encode_b_type funct3: %d \n", funct3);
    // printf("encode_b_type opcode: %d \n", opcode);

    // return ((opcode & 0b1111111) << 0) |
    //        ((imm & 0b11111) << 7) |
    //        ((funct3 & 0b111) << (7+5)) |
    //        ((rs1 & 0b11111) << (7+5+3)) |
    //        ((rs2 & 0b11111) << (7+5+3+5)) |
    //        ((imm & 0b111111100000) << (7+5+3+5+5));

    uint32_t imm_11 = (imm >> 10) & 0b1;
    uint32_t imm_4_1 = (imm >> 1) & 0b1111;
    uint32_t imm_10_5 = (imm >> 5) & 0b111111;
    uint32_t imm_12 = (imm >> 11) & 0b1;

    return ((opcode & 0b1111111) << 0) |
           ((imm_11) << 7) |
           ((imm_4_1) << (7+1)) |
           ((funct3 & 0b111) << (7+1+4)) |
           ((rs1 & 0b11111) << (7+1+4+3)) |
           ((rs2 & 0b11111) << (7+1+4+3+5)) |
           ((imm_10_5 & 0b111111) << (7+1+4+3+5+5)) |
           ((imm_12 & 0b1) << (7+1+4+3+5+5+6));

}

// imm[31:12] rd opcode
uint32_t encode_u_type(uint32_t imm, uint8_t rd, uint8_t opcode) {

    //printf("encode_u_type opcode: %d \n", opcode);
    //printf("encode_u_type rd: %d \n", rd);
    //printf("encode_u_type imm: %d \n", imm);
    //printf("encode_u_type imm: %08" PRIx32 "\n", imm);

    return ((opcode & 0b1111111) << 0) |
           ((rd & 0b11111) << 7) |
           ((imm & 0b11111111111111111111) << (7+5));
}

// imm[20] imm[10:1] imm[11] imm[19:12] rd opcode
uint32_t encode_j_type(int32_t imm, uint8_t rd, uint8_t opcode) {

    uint16_t imm_20 = (imm >> 19) & 0b1; // 1
    uint16_t imm_10_1 = (imm >> 1) & 0b1111111111; // 10
    uint16_t imm_11 = (imm >> 10) & 0b1; // 1
    uint16_t imm_19_12 = (imm >> 11) & 0b11111111; // 8

    return ((opcode & 0b1111111) << 0) |
           ((rd & 0b11111) << 7) |
           ((imm_19_12 & 0b11111111) << (7+5)) |
           ((imm_11 & 0b1) << (7+5+8)) |
           ((imm_10_1 & 0b1111111111) << (7+5+8+1)) |
           ((imm_20 & 0b1) << (7+5+8+1+10));
}

uint32_t encode(asm_line_t* asm_line) {

    //print_asm_line(asm_line);

    if (asm_line->use_raw_data) {
        return asm_line->raw_data;
    }

    uint32_t encoded_asm_line = 0;
    uint32_t output_buffer[2];

    switch (asm_line->instruction) {

        case I_AUIPC:
            encoded_asm_line = encode_auipc(asm_line);
            break;

        case I_ADD:
            encoded_asm_line = encode_add(asm_line);
            break;

        case I_ADDI:
            encoded_asm_line = encode_addi(asm_line);
            break;

        // ADDIW is part of RV64I not RV32I. Only generate this instruction if the extension RV64I is enabled !!!
        case I_ADDIW:
            encoded_asm_line = encode_addiw(asm_line);
            break;

        case I_MUL:
            encoded_asm_line = encode_mul(asm_line);
            break;

        case I_BEQ:
            encoded_asm_line = encode_beq(asm_line);
            break;

        case I_BNE:
            encoded_asm_line = encode_bne(asm_line);
            break;

        case I_BGE:
            encoded_asm_line = encode_bge(asm_line);
            break;

        case I_BLT:
            encoded_asm_line = encode_blt(asm_line);
            break;

        case I_JAL:
            encoded_asm_line = encode_jal(asm_line);
            break;

        case I_JALR:
            encoded_asm_line = encode_jalr(asm_line);
            break;

        case I_LUI:
            encoded_asm_line = encode_lui(asm_line);
            break;

        case I_LB:
            encoded_asm_line = encode_lb(asm_line);
            break;

        case I_LH:
            encoded_asm_line = encode_lh(asm_line);
            break;

        case I_LW:
            encoded_asm_line = encode_lw(asm_line);
            break;

        case I_LD:
            encoded_asm_line = encode_ld(asm_line);
            break;

        case I_SRLI:
            encoded_asm_line = encode_srli(asm_line);
            break;

        case I_SLLI:
            encoded_asm_line = encode_slli(asm_line);
            break;

        case I_SD:
            encoded_asm_line = encode_sd(asm_line);
            break;

        case I_SW:
            encoded_asm_line = encode_sw(asm_line);
            break;

        case I_SH:
            encoded_asm_line = encode_sh(asm_line);
            break;

        case I_SB:
            encoded_asm_line = encode_sb(asm_line);
            break;

        default:
            printf("encoder.c - ERROR Unknown instruction! %s \n", instruction_to_string(asm_line->instruction));
            printf("encoder.c - ERROR Unknown instruction! %s \n", instruction_to_string(asm_line->instruction));
            printf("encoder.c - ERROR Unknown instruction! %s \n", instruction_to_string(asm_line->instruction));
            printf("encoder.c - ERROR Unknown instruction! %s \n", instruction_to_string(asm_line->instruction));
            printf("encoder.c - ERROR Unknown instruction! %s \n", instruction_to_string(asm_line->instruction));
            printf("encoder.c - ERROR Unknown instruction! %s \n", instruction_to_string(asm_line->instruction));
            printf("Aborting the application!\n");
            abort();
            return 0;
    }

    return encoded_asm_line;
}
