#ifndef CALL_DECODE_TEST
#define CALL_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "decoder.h"

void call_decode_valid_input_test(void **state);

#endif