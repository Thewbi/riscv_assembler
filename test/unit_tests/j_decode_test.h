#ifndef J_DECODE_TEST
#define J_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void j_decode_valid_input_test(void **state);

#endif