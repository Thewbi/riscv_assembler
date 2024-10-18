#ifndef COMMON
#define COMMON

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint16_t sign_extend_uint16_t(uint16_t data);
uint32_t sign_extend_12_bit_to_uint32_t(const uint16_t data);
uint32_t sign_extend_20_bit_to_uint32_t(const uint32_t data);

#endif