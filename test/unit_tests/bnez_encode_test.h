#ifndef BNEZ_ENCODE_TEST
#define BNEZ_ENCODE_TEST

#include <setjmp.h>
#include <cmocka.h>

#include "asm_line.h"
#include "parser.h"
#include "encoder.h"

void bnez_encode_valid_input_test(void **state);

#endif