# Load byte unsigned (lbu)
#
# Format:
# lbu rd, offset(rs1)
#
# Specification:
# offset is 12 bit in size
# rd <-- byte from address rs1 + offset
#
# Example:
# lbu x0, 0(x0)
#
#lbu a4, %lo(LSR.2)(a4)
lbu x0, 0(x0)