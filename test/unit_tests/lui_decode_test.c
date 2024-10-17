#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <lui_decode_test.h>

void lui_decode_valid_input_test(void **state) {

    // Arrange

    // https://luplab.gitlab.io/rvcodecjs/#q=lui+a0,0xdeadc&abi=false&isa=AUTO
    // lui a0, 0xdeadc
    uint32_t data = 0xdeadc537;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_LUI, asm_line.instruction);
    assert_int_equal(R_A0, asm_line.reg_rd);

    int32_t offset_immediate = -136484;
    int32_t value = asm_line.imm;
    assert_int_equal(offset_immediate & 0xFFFFF, value);

}