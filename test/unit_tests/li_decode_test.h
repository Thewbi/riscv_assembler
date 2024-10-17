#ifndef LI_DECODE_TEST
#define LI_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void li_decode_valid_input_test(void **state);

#endif