# Usually li is replace by lui, addi
#
# Here the lower 12 bits of the immediate are zero, so the addi is not generated

.equ IO_BASE, 0x400000
li   gp, IO_BASE