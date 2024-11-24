# https://stackoverflow.com/questions/76331514/riscv-li-instruction


# in RISCV assembly, "li" is an pseudoinstruction. I have this instruction:

li      t2, 0x1800

# The "li" is assembled into following 2 instruction.

# lui x7 2
# addi x7 x7 -2048

# or on risc 64 bit using addiw

# lui x7 2
# addiw x7 x7 -2048

# My question , why 2 and -2048? and why "li" assembled into lui and addi? are there a document for this kind of behavior?

# I have used "riscv64-unknown-elf-as" as assembler.


# The unoptimized sequence could be:

# lui x7, 1
# addi x7, x7, 0x400
# addi x7, x7, 0x400

# achieving 0x1000 + 0x400 + 0x400 = 0x1800.

# but optimized will be:

# 8192 + -2048 = 6144 with 6144=0x1800.