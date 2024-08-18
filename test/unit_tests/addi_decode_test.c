#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <setjmp.h>
#include <cmocka.h>

#include <decoder.h>
#include <addi_decode_test.h>

#include "asm_line.h"

void addi_decode_valid_input_test(void **state) {

    // Arrange

    // https://www.eg.bucknell.edu/~csci206/riscv-converter/index.html
    // add    t1, t0, a0  == 0x00A28333 = 0000000 01010 00101 000 00110 0110011
    uint32_t data = 0x00A28333;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_ADD, asm_line.instruction);
    assert_int_equal(R_T1, asm_line.reg_rd);
    assert_int_equal(R_T0, asm_line.reg_rs1);
    assert_int_equal(R_A0, asm_line.reg_rs2);

}