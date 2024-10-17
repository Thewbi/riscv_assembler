#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <mv_decode_test.h>

// mv (move) is a pseudoinstruction. It is implemented using: 
// mv rd, rs --> addi rd, rs, 0
// mv a0, a5 --> addi a0, a5, 0
void mv_decode_valid_input_test(void **state) {

    // Arrange

    // https://luplab.gitlab.io/rvcodecjs/#q=addi+a0,+a5,+0&abi=false&isa=AUTO
    // addi a0, a5, 0
    // addi x10, x15, 0
    uint32_t data = 0x00078513;
    asm_line_t asm_line;

    // Act

    decode(data, &asm_line);

    // Assert

    assert_int_equal(I_ADDI, asm_line.instruction);
    assert_int_equal(R_A5, asm_line.reg_rs1);
    assert_int_equal(R_A0, asm_line.reg_rd);
    assert_int_equal(0, asm_line.imm);

}