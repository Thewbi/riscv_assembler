# source: https://www.riscfive.com/2022/04/28/risc-v-assembly-tutorial/
# file: for_loop.s
#
# for (int i = 0; i < 10; i++) {
#    // Repeated code goes here.
# }

    li t0, 0        # t0 = 0
    li t2, 10

loop_head:
    bge t0, t2, loop_end
                    # Repeated code goes here
    addi t0, t0, 1
    j loop_head

loop_end: