#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <mul_decode_test.h>

void mul_decode_valid_input_test(void **state) {

    // Arrange

    // https://luplab.gitlab.io/rvcodecjs/#q=mul+++++a5,a5,a5&abi=false&isa=AUTO
    // mul  a5,  a5,  a5
    // mul x15, x15, x15
    uint32_t data = 0x02f787b3;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_MUL, asm_line.instruction);
    assert_int_equal(R_A5, asm_line.reg_rs1);
    assert_int_equal(R_A5, asm_line.reg_rs2);
    assert_int_equal(R_A5, asm_line.reg_rd);

}