# test for modifier %hi
# https://sourceware.org/binutils/docs/as/RISC_002dV_002dModifiers.html
#
# %lo(symbol)
# The low 12 bits of absolute address for symbol.
#
# %hi(symbol)
# The high 20 bits of absolute address for symbol.
#
# This is usually used with the %lo modifier to represent a 32-bit absolute address.

uart:   .word   0x10000000
        lui     a5, %hi(uart)