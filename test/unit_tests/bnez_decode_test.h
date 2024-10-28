#ifndef BNEZ_DECODE_TEST
#define BNEZ_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void bnez_decode_valid_input_test(void **state);

#endif