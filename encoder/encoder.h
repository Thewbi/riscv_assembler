#ifndef _ENCODER
#define _ENCODER

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "asm_line.h"

/**
 * Place the address of this function into the 'emit' function pointer
 * of the parser to feed all parsed lines into the encoder directly while
 * the parser parses lines.
 */
void encoder_callback(asm_line_t* asm_line);

/**
 * https://www.eg.bucknell.edu/~csci206/riscv-converter/
 * 
 * https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf - page 104
 */
uint32_t encode_add(asm_line_t* asm_line);

uint32_t encode_addi(asm_line_t* asm_line);

uint32_t encode_beq(asm_line_t* asm_line);

uint32_t encode_lw(asm_line_t* asm_line);

uint32_t encode_mul(asm_line_t* asm_line);

uint32_t encode_mv(asm_line_t* asm_line);

uint32_t encode_srli(asm_line_t* asm_line);

uint32_t encode_slli(asm_line_t* asm_line);

uint32_t encode_sw(asm_line_t* asm_line);

uint8_t encode_register(enum register_ data);

uint32_t encode_r_type(uint8_t funct7, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode);

uint32_t encode_i_type(uint16_t imm, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode);

uint32_t encode_b_type(uint16_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode);

uint32_t encode_s_type(uint16_t imm, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t opcode);

#endif