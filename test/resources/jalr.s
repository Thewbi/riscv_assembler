// The indirect jump instruction JALR (jump and link register) uses the I-type encoding.
//
// The target address is obtained by adding the 12-bit signed I-immediate to the register rs1,
// then setting the least-significant bit of the result to zero.
//
// The address of the instruction following the jump (pc+4) is written to register rd.
// Register x0 can be used as the destination if the result is not required.
//
// jalr ra, ra, imm12
// jalr rd, imm12(rs1)
//
// rd <-- pc + 4
// pc <-- rs1 + imm12
//

// jalr rd, imm(rs1)  # rd = pc+4; pc = rs1+imm (imm is modified: least-significant bit of the result to zero)

//jalr zero, 0(ra)

jalr x0, 0xc00(x5)