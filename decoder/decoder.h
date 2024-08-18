#ifndef _DECODER
#define _DECODER

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "asm_line.h"

void decode(uint32_t data, asm_line_t* asm_line);

void decode_r_type(uint32_t data, asm_line_t* asm_line);
void decode_i_type(uint32_t data, asm_line_t* asm_line);

enum register_ decode_register(uint8_t data);

#endif