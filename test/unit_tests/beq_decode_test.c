#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <beq_decode_test.h>

void beq_decode_valid_input_test(void **state) {

    // Arrange

    // https://www.eg.bucknell.edu/~csci206/riscv-converter/index.html
    // https://luplab.gitlab.io/rvcodecjs/
    // beq  s0, s1, 0x10  == 00940863 
    uint32_t data = 0x00940863;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_BEQ, asm_line.instruction);
    assert_int_equal(R_S0, asm_line.reg_rs1);
    assert_int_equal(R_S1, asm_line.reg_rs2);
    assert_int_equal(16, asm_line.imm);

}