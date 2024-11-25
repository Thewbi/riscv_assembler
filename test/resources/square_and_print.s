# source: https://mcyoung.xyz/2021/11/29/assembly-1/

.text
        .file   "square.c"
        .globl  square_and_print
square_and_print:
        addi    sp, sp, -16
        sw      ra, 12(sp)
        sw      s0, 8(sp)
        mul     s0, a0, a0
        lui     a0, %hi(.L.str)
        addi    a0, a0, %lo(.L.str)
        mv      a1, s0
#        call    printf
        mv      a0, s0
        lw      s0, 8(sp)
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .section        .rodata
.L.str:
        .asciz  "%d\n"
