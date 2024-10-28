#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <bne_decode_test.h>

void bne_decode_valid_input_test(void **state) {

    // Arrange

    // https://www.eg.bucknell.edu/~csci206/riscv-converter/index.html
    // https://luplab.gitlab.io/rvcodecjs/
    // https://luplab.gitlab.io/rvcodecjs/#q=bne+t3,+t4,+100&abi=false&isa=AUTO
    // bne x28, x29, 100  == 0x07de1263 
    uint32_t data = 0x07de1263;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_BNE, asm_line.instruction);
    assert_int_equal(R_T3, asm_line.reg_rs1);
    assert_int_equal(R_T4, asm_line.reg_rs2);
    assert_int_equal(100, asm_line.imm);

}