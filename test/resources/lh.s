// Format:
// lh rd, imm(rs1)
//
// Specification:
// lh: rd = mem[rs1+imm][0:15] ; load half word

lh a0, 1(a0)