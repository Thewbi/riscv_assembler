.globl argmax

.text
# =================================================================
# FUNCTION: Given a int vector, return the index of the largest
#	element. If there are multiple, return the one
#	with the smallest index.
# Arguments:
# 	a0 (int*) is the pointer to the start of the vector
#	a1 (int)  is the # of elements in the vector
# Returns:
#	a0 (int)  is the first index of the largest element
#
# If the length of the vector is less than 1,
# this function exits with error code 7.
# =================================================================
argmax:                                                         # addr: 0

    addi sp, sp, -12                                            # addr: 4
    sw s0, 0(sp)
    sw s1, 4(sp)            # loaded val                        # addr: 8
    sw s2, 8(sp)            # max index                         # addr: 12

    addi t0, x0, 1                                              # addr: 16
    blt a1, t0, exit7                                           # addr: 20
    j loop_start                                                # addr: 24

exit7:                                                          # addr: 28
    li a1, 7                                                    # addr: 28
    j exit2                 # this will not assemble since the label exit2 is not defined # addr: 32

loop_start:                                                     # addr: 36
    addi t0, x0, 0          # i = 0                             # addr: 36
    addi t1, x0, 0          # max val                           # addr: 40
    addi t2, x0, 0          # iteration comp                    # addr: 44

    j loop_continue                                             # addr: 48

loop_continue:                                                  # addr: 52
    beq t0, a1, loop_end                                        # addr: 52

    add a0, a0, t2          # increment index                   # addr: 56
    lw s1, 0(a0)            # load index                        # addr: 60
    addi t2, x0, 4          # ready to get next value           # addr: 64

    bgt s1, t1, newmax      # see if num is larger than max     # addr: 68

    addi t0, t0, 1                                              # addr: 72
    j loop_continue                                             # addr: 76

newmax:                                                         # addr: 80
    addi t1, s1, 0          # set new max value                 # addr: 80
    addi s2, t0, 0          # set max index                     # addr: 84

    addi t0, t0, 1                                              # addr: 88
    j loop_continue                                             # addr: 92

loop_end:                                                       # addr: 96
                            # Epilogue
    mv a0, s2                                                   # addr: 96

    lw s0, 0(sp)                                                # addr: 100
    lw s1, 4(sp)                                                # addr: 104
    lw s2, 8(sp)                                                # addr: 108
    addi sp, sp, 12                                             # addr: 112

exit2:                                                          # addr: 116
    ret                                                         # addr: 116




# Source: https://github.com/kcelebi/riscv-assembler/blob/main/tests/assembly/prjtest1/argmax.s
#
# Only this file is under the MIT licence, the rest is not!!!!!!
#
# MIT License
#
# Copyright (c) 2020 Kaya Celebi
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.