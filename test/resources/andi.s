# logical and with immediate (andi)
# ANDI, ORI, XORI are logical operations that perform bitwise AND, OR, and XOR on register rs1
# and the sign-extended 12-bit immediate and place the result in rd
#
# Format:
# andi rd, rs1, imm12
#
# Specification:
# imm is 12 bit in size
# rd <-- rs1 & imm12
#
# Example:
# andi x0, x0, 0
#
andi x0, x0, 0