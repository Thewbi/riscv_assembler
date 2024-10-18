// https://www.reddit.com/r/RISCV/comments/129qg6t/can_someone_pls_explain/?tl=de
//
// j is a pseudo instruction. It jumps to a target address which is computed 
// using the current pc value and an immediate value (= pc relative).
//
// j imm
//
// pc <-- pc + imm
//
// The pseudo instruction j is implemented by a call to auipc followed by a jalr
// instruction.
// auipc loads the upper 20 bits of an immedatiate to pc and stores the result in a register.
// jalr loads the lower 12 bits given by an immediate to a register value and stores the result into pc.
// In effect the combination of auipc and jalr load a 32 bit value into pc if the temporary
// register used in the auipc command is also used in the jalr command.
//
// 
//
// example:
// Assume the pc contains 0x40000000 and the user executes j 0x2FFFC00/4 == j 0xBFFF00
//
// 1. Take the value 0xBFFF00 and multiply it by 4 because it is the amount of instructions with 4 byte per instruction
// 0xBFFF00 * 4 = 0x02FFFC00 = data_1
//
// 2. Take the lower 12 bits of data_1 (0xC00) = data_2
//
// 3. interpret data_2 as a sign extended value: 
// In my calculator app, a number is sign extended only if you enter it as a 64 bit value:
// 0xFFFFFFFFFFFFFC00 == -1024 = data_3
//
// 4. Take this negative value (data_3), invert the sign and add it to the original value (data_1).
// 0x02FFFC00 + 1024 = 0x3000000 = data_4
//
// 5. Take only the upper 20 bits of data_4
// 0x3000000 >> 12 == 0x3000 = data_5
//
// 6. Select a free temporary register (here: x5)
//
// 7. Take data_5 and create an aupic instruction
// auipc x5, 0x3000
//
// 8. Take data_2 and create a jalr instruction. Use data_2 as the offset.
// jalr x0, 0xc00(x5)


j 0x00BFFF00



// https://marz.utk.edu/my-courses/cosc230/book/example-risc-v-assembly-programs/
// jump 1 backwards
//j      1b

// jump two forward
// j       2f

// https://www.reddit.com/r/RISCV/comments/13rcn8e/when_to_use_j_jal_jr_jalr/#:~:text=The%20%22j%22%20instruction%20is%20used,program%20counter%20(PC)%20value.
// implemented by auipc and jalr

// jalr - jump and link register
// jalr rd, 
//
// load the pc with 
// jalr x0, 0xc00(x5)

// The idea is to jump relative to the current program counter (pc) value.
//
// To load a new value into the pc, 