#ifndef SLLI_DECODE_TEST
#define SLLI_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void slli_decode_valid_input_test(void **state);

#endif