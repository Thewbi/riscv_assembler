#ifndef BEQ_DECODE_TEST
#define BEQ_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void beq_decode_valid_input_test(void **state);

#endif