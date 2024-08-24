#ifndef BEQ_ENCODE_TEST
#define BEQ_ENCODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "parser.h"
#include "encoder.h"

void beq_encode_valid_input_test(void **state);

#endif