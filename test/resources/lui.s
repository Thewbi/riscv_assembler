// https://luplab.gitlab.io/rvcodecjs/#q=lui+a0,+0xdeadc&abi=false&isa=AUTO
// lui x10, -136484
// 0xdeadc537
// U-type
//
// loads a 20 bit immediate constant into the upper 20 bits of the register.
//
// LUI (load upper immediate) is used to build a 32-bit constants and uses the U-type format. 
// LUI places the U-immediate value in the top 20 bits of the destination register rd, 
// filling in the lowest 12 bits with zeros.

lui a0, 0xdeadc