// https://www.reddit.com/r/RISCV/comments/129qg6t/can_someone_pls_explain/?tl=de
//
// adds a 20-bit upper immediate to the PC and stores the computed result into the rd register
//
// auipc rd, imm    <=>    rd <-- pc + (imm << 12)
//
// U-type

//auipc x5, 0x03000
auipc t0, 0x03000