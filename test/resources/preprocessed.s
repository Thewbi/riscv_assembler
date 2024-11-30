# Simple blinker
# Code is taken from here: https://github.com/BrunoLevy/learn-fpga/blob/master/FemtoRV/TUTORIALS/FROM_BLINKER_TO_RISCV/README.md
# File: blinker.s

# https://michaeljclark.github.io/asm.html

# assemble for testing here: https://riscvasm.lucasteske.dev/#

# 1. Parse all lines into asm_line objects. For each instruction, store the amount of bytes it will take so that
#    the label addresses can be computed correctly. All instructions take up 4 byte (32 bit) except for
#    pseudo instructions which are resolved to more than 4 byte (mostly 8 byte)
#    Do not resolve pseudo instructions just yet because labels and symbols are not replaced by concrete values
# 2. Build a map from labels and symbols to addresses or values
# 3. Replace all labels and symbols by numeric values (address or values) in each asm_line
#    For addresses, remember that not each line is 4 byte long but use the length stored in each asm_line instead of just 4
# 4. Replace all pseudo instructions by real instruction asm_line objects
# 5. Encode asm_line objects into 32 bit machine code

.equ IO_BASE, 0x400000
.equ IO_LEDS, 4

.section .text

.globl start

start:                          #  0        # addr: 0
    li   gp, IO_BASE            #  0 +8     # addr: 0
    li   sp, 0x1800             #  8 +8     # addr: 4
.L0:                            # 16        # addr: 8
    li   t0, 5                  # 16 +8     # addr: 8
    sw   t0, IO_LEDS(gp)        # 24 +4     # addr: 12
    call wait                   # 28 +8     # addr: 16
    li   t0, 10                 # 36 +8     # addr: 20
    sw   t0, IO_LEDS(gp)        # 44 +4     # addr: 24
    call wait                   # 48 +8     # addr: 28 (encoded to jal)
    j    .L0                    # 56 +8     # addr: 32
wait:                           # 64        # addr: 36
    li   t0, 1                  # 64 +8     # addr: 36
    slli t0, t0, 17             # 72 +4     # addr: 40
.L1:                            # 76        # addr: 44
    addi t0, t0, -1             # 76 +4     # addr: 44
    bnez t0, .L1                # 80 +4     # addr: 48
    ret                         # 84 +4     # addr: 52
