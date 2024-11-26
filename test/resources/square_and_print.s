# source: https://mcyoung.xyz/2021/11/29/assembly-1/

        .text
        .file   "square.c"
        .globl  square_and_print
square_and_print:                       # addr: 0
        addi    sp, sp, -16             # addr: 0
        sw      ra, 12(sp)              # addr: 4
        sw      s0, 8(sp)               # addr: 8
        mul     s0, a0, a0              # addr: 12
        lui     a0, %hi(.L.str)         # addr: 16
        addi    a0, a0, %lo(.L.str)     # addr: 20
        mv      a1, s0                  # addr: 24
#        call    printf
        mv      a0, s0                  # addr: 28
        lw      s0, 8(sp)               # addr: 32
        lw      ra, 12(sp)              # addr: 36
        addi    sp, sp, 16              # addr: 40
        ret                             # addr: 44

        .section        .rodata
.L.str:
        .asciz  "%d\n"
