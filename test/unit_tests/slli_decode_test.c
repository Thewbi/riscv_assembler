#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <slli_decode_test.h>

void slli_decode_valid_input_test(void **state) {

    // Arrange

    // https://www.eg.bucknell.edu/~csci206/riscv-converter/index.html
    // https://luplab.gitlab.io/rvcodecjs/
    // slli s1, s1, 2  == 0x00249493 = 0000 0000 0010 0100 1001 0100 1001 0011
    uint32_t data = 0x00249493;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_SLLI, asm_line.instruction);
    assert_int_equal(R_S1, asm_line.reg_rd);
    assert_int_equal(R_S1, asm_line.reg_rs1);
    assert_int_equal(2, asm_line.imm);

}