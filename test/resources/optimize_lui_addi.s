# One possible optimization is to recombine a combination of lui and addi
# (which were manually added by a developer) into a li pseudo instruction.
# The assembler can then resolve li into a potentially optimized smaller
# amount of instructions.
#
# For example:
# li -> addi if upper_part_used == 0 && lower_part_used == 0
# li -> addi if (upper_part_used == 0 && lower_part_used != 0)
# if -> lui if (upper_part_used != 0 && lower_part_used == 0)
#
# Effect of %hi(), %lo(): https://sourceware.org/binutils/docs/as/RISC_002dV_002dModifiers.html
# %lo(symbol) - The low 12 bits of absolute address for symbol.
# %hi(symbol) - The high 20 bits of absolute address for symbol.
#
# Code that can be optimized looks like this:

lui     a0, %hi(.L.str)         # addr: 16
addi    a0, a0, %lo(.L.str)     # addr: 20

# This is basically the same as a li pseudo instruction
# If the assembler could detect a li here, it can then potentially optimize
# the li to a simple addi or lui
#
# To detect this pattern
# 1. the same register R is used for lui.reg_rd, addi.reg_rd and addi.reg_rs1
# 2. the syme symbol is used in %hi(symbol) and %lo(symbol)
#
# The optimized output is:
# li a0, .L.str