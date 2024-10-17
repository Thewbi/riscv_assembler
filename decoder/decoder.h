#ifndef _DECODER
#define _DECODER

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "../data/asm_line.h"

uint16_t sign_extend_uint16_t(uint16_t data);

void decode(uint32_t data, asm_line_t* asm_line);

void decode_r_type(uint32_t data, asm_line_t* asm_line);
void decode_i_type(uint32_t data, asm_line_t* asm_line, uint8_t funct7, uint8_t funct3);
void decode_s_type(uint32_t data, asm_line_t* asm_line);
void decode_b_type(uint32_t data, asm_line_t* asm_line);
void decode_u_type(uint32_t data, asm_line_t* asm_line);
void decode_j_type(uint32_t data, asm_line_t* asm_line);

enum register_ decode_register(uint8_t data);

#endif