// Call far-away subroutine
//
// call offset
//
// auipc x6, offset[31:12] 
// jalr x1, x6, offset[11:0]

call 0x0BFFFC00