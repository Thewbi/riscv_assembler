#ifndef LUI_DECODE_TEST
#define LUI_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void lui_decode_valid_input_test(void **state);

#endif