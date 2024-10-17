#ifndef MV_DECODE_TEST
#define MVS_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void mv_decode_valid_input_test(void **state);

#endif