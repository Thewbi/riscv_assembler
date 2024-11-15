// https://stackoverflow.com/questions/56781564/how-to-load-an-immediate-number-to-a-register-in-rv32i-base-instruction-set

//.equ  CONSTANT, 0xdeadbeef
//li    a0, CONSTANT

// pseudo instruction
// implemented by lui, addi, slli, addi (according to https://michaeljclark.github.io/asm.html#:~:text=The%20li%20(load%20immediate)%20instruction,constants%20by%20shifting%20and%20adding.)

li a0, 0xdeadbeef