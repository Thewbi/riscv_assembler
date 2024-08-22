#ifndef SRLI_DECODE_TEST
#define SRLI_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void srli_decode_valid_input_test(void **state);

#endif