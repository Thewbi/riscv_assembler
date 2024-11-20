// load byte
//
// Format 1:
// lb rd, imm12(rs1)
//
// Format 2:
//
//
// Specification:
// rd = mem[rs1+imm12][0:7]

lb     t1, 123(t1)
//lb      a0, 0xFF