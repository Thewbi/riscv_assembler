# Branch if rs1 greater than or equal rs2
#
# Format:
# bge rs1, rs2, offset
#
# Specification:
# if rs1 >= rs2 then pc += offset.
#
# The offset is added to pc. This means that the immediate offset value is relative
# to the current assembly line. So to jump to a lable that is two lines ahead,
# use an offset of 8. 8 because this means to jump two lines ahead as each
# line is 4 byte.

bge a1, t0, 10