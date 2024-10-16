#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <srli_decode_test.h>

void srli_decode_valid_input_test(void **state) {

    // Arrange

    // https://luplab.gitlab.io/rvcodecjs/#q=0x011ad493&abi=false&isa=AUTO
    // srli x9, x21, 17
    // srli s1, s5, 17
    uint32_t data = 0x011ad493;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_SRLI, asm_line.instruction);
    assert_int_equal(R_S1, asm_line.reg_rd);
    assert_int_equal(R_S5, asm_line.reg_rs1);
    assert_int_equal(17, asm_line.imm);

}