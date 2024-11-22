# source: https://www.riscfive.com/2022/04/28/risc-v-assembly-tutorial/
# void my_function();

my_function:
    # Prologue
    addi    sp, sp, -32
    sd      ra, 0(sp)
    sd      a0, 8(sp)
    sd      s0, 16(sp)
    sd      s1, 24(sp)

    # Epilogue
    ld      ra, 0(sp)
    ld      a0, 8(sp)
    ld      s0, 16(sp)
    ld      s1, 24(sp)
    addi    sp, sp, 32
    ret