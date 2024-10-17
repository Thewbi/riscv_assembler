#ifndef SW_DECODE_TEST
#define SW_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void sw_decode_valid_input_test(void **state);

#endif