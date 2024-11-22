// https://stackoverflow.com/questions/56781564/how-to-load-an-immediate-number-to-a-register-in-rv32i-base-instruction-set
//
// example:
// .equ  CONSTANT, 0xdeadbeef
// li    a0, CONSTANT
//
// pseudo instruction
//
// implemented by lui, addi, slli, addi (according to https://michaeljclark.github.io/asm.html#:~:text=The%20li%20(load%20immediate)%20instruction,constants%20by%20shifting%20and%20adding.)
//
// Case 1: CONSTANT fits into 12 bit. For CASE 1, a addi instruction is generated since addi handles 12 bit sufficiently
//
// Case 2: CONSTANT fits into 32 bit. For CASE 2, a LUI, ADDI combination is generated
//
// Case 3: CONSTANT fits into 64 bit. For CASE 3, ??? I think a lui, addi, slli, addi combination handles case 3 maybe????

li a0, 0xdeadbeef