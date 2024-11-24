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


# Test 1: load a zero
#li t0, 0x00

# Test 2: load only lower 12 bits
#li t0, 0x05

# Test 3: load only upper 20 bits
#li t0, 0x8000

# Test 4: load both lower and upper
#li t0, 0x8001

# Test 5: load a value where the lower 12 bits have the most significant bit set (negative value)
# Test 5 may output an optimized lui, addi or lui, addiw sequence (see: https://stackoverflow.com/questions/76331514/riscv-li-instruction)
#li   sp, 0x1800