#ifndef BNE_DECODE_TEST
#define BNE_DECODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "parser.h"
#include "decoder.h"

void bne_decode_valid_input_test(void **state);

#endif