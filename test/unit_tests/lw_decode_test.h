#ifndef LW_DECODE_TEST
#define LW_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void lw_decode_valid_input_test(void **state);

#endif