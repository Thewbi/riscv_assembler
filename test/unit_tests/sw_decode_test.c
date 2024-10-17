#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <sw_decode_test.h>

void sw_decode_valid_input_test(void **state) {

    // Arrange

    // https://luplab.gitlab.io/rvcodecjs/#q=sw+ra,+28(sp)&abi=false&isa=AUTO
    // sw ra, 28(sp)
    uint32_t data = 0x00112e23;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_SW, asm_line.instruction);
    assert_int_equal(R_SP, asm_line.reg_rs1);
    assert_int_equal(R_RA, asm_line.reg_rs2);
    assert_int_equal(28, asm_line.imm);

}