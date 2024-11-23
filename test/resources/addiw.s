# ADDIW is an RV64I-only instruction that adds the sign-extended 12-bit immediate to register rs1
# and produces the proper sign-extension of a 32-bit result in rd. Overflows are ignored and the
# result is the low 32 bits of the result sign-extended to 64 bits. Note, ADDIW rd, rs1, 0 writes the
# sign-extension of the lower 32 bits of register rs1 into register rd (assembler pseudo-op SEXT.W).

addiw x3, x3, 1