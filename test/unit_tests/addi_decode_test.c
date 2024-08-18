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
    // addi    t0, t0, 15  == 0x00F28293 = 1111 00101 000 00101 0010011
    uint32_t data = 0x00F28293;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_ADDI, asm_line.instruction);
    assert_int_equal(R_T0, asm_line.reg_rd);
    assert_int_equal(R_T0, asm_line.reg_rs1);
    assert_int_equal(15, asm_line.imm);

}