# Simple blinker
# Code is taken from here: https://github.com/BrunoLevy/learn-fpga/blob/master/FemtoRV/TUTORIALS/FROM_BLINKER_TO_RISCV/README.md

# https://michaeljclark.github.io/asm.html

# assemble for testing here: https://riscvasm.lucasteske.dev/#

# 1. Parse all lines into asm_line objects. For each instruction, store the amount of bytes it will take so that
#    the label addresses can be computed correctly. All instructions take up 4 byte (32 bit) except for
#    pseudo instructions which are resolved to more than 4 byte (mostly 8 byte)
#    Do not resolve pseudo instructions just yet because labels and symbols are not replaced by concrete values
# 2. Build a map from labels and symbols to addresses or values
# 3. Replace all labels and symbols by numeric values (address or values) in each asm_line
#    For addresse, remember that not each line is 4 byte long but use the length stored in each asm_line instead of just 4
# 4. Replace all pseudo instructions by real instruction asm_line objects
# 5. Encode asm_line objects into 32 bit machine code

.equ IO_BASE, 0x400000
.equ IO_LEDS, 4

.section .text

.globl start

start:
    li   gp, IO_BASE
    li   sp, 0x1800
.L0:
    li   t0, 5
    sw   t0, IO_LEDS(gp)
    call wait
    li   t0, 10
    sw   t0, IO_LEDS(gp)
    call wait
    j    .L0
wait:
    li   t0, 1
    slli t0, t0, 17
.L1:
    addi t0, t0, -1
    bnez t0, .L1
    ret