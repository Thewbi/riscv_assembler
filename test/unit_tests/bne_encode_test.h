#ifndef BNE_ENCODE_TEST
#define BNE_ENCODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "parser.h"
#include "encoder.h"

void bne_encode_valid_input_test(void **state);

#endif