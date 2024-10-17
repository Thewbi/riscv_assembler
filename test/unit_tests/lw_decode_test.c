#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <lw_decode_test.h>

void lw_decode_valid_input_test(void **state) {

    // Arrange

    // https://luplab.gitlab.io/rvcodecjs/#q=lw++++++a5,-20(s0)&abi=false&isa=AUTO
    // lw  a5, -20(s0)
    // lw x15, -20(x8)
    uint32_t data = 0xfec42783;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_LW, asm_line.instruction);
    assert_int_equal(R_S0, asm_line.reg_rs1);
    assert_int_equal(R_A5, asm_line.reg_rd);

    uint16_t offset_immediate = -20;
    assert_int_equal(offset_immediate, asm_line.imm);

}