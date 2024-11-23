#ifndef _ENCODER
#define _ENCODER

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "../common/common.h"
#include "../common/register.h"
#include "asm_line.h"

/**
 * Place the address of this function into the 'emit' function pointer
 * of the parser to feed all parsed lines into the encoder directly while
 * the parser parses lines.
 */
void encoder_callback(asm_line_t* asm_line);

uint32_t encode(asm_line_t* asm_line);

/**
 * https://www.eg.bucknell.edu/~csci206/riscv-converter/
 *
 * https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf - page 104
 */
uint32_t encode_add(asm_line_t* asm_line);

uint32_t encode_addi(asm_line_t* asm_line);

uint32_t encode_auipc(asm_line_t* asm_line);

uint32_t encode_beq(asm_line_t* asm_line);

uint32_t encode_bge(asm_line_t* asm_line);

uint32_t encode_bne(asm_line_t* asm_line);

uint32_t encode_bnez(asm_line_t* asm_line);

void encode_call(asm_line_t* asm_line, uint32_t* output_buffer);

void encode_j(asm_line_t* asm_line, uint32_t* output_buffer);

uint32_t encode_lb(asm_line_t* asm_line);

uint32_t encode_lh(asm_line_t* asm_line);

uint32_t encode_lw(asm_line_t* asm_line);

uint32_t encode_ld(asm_line_t* asm_line);

uint32_t encode_sb(asm_line_t* asm_line);

uint32_t encode_sh(asm_line_t* asm_line);

uint32_t encode_sw(asm_line_t* asm_line);

uint32_t encode_dw(asm_line_t* asm_line);

uint32_t encode_lui(asm_line_t* asm_line);

void encode_li(asm_line_t* asm_line, uint32_t* output_buffer);

uint32_t encode_mul(asm_line_t* asm_line);

//uint32_t encode_mv(asm_line_t* asm_line);

uint32_t encode_ret(asm_line_t* asm_line);

uint32_t encode_srli(asm_line_t* asm_line);

uint32_t encode_slli(asm_line_t* asm_line);

uint32_t encode_sw(asm_line_t* asm_line);

uint8_t encode_register(enum register_ data);

uint32_t encode_r_type(uint8_t funct7, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode);

uint32_t encode_i_type(uint16_t imm, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode);

uint32_t encode_s_type(uint16_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode);

uint32_t encode_u_type(uint32_t imm, uint8_t rd, uint8_t opcode);

uint32_t encode_b_type(uint16_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode);

uint32_t encode_j_type(int32_t imm, uint8_t rd, uint8_t opcode);

#endif