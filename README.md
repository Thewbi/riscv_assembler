# riscv_assembler

RISCV assembler

## Usage

Go to the releases section on github https://github.com/Thewbi/riscv_assembler.
Download the executable.

To assemble a RISC-V assembler file.

```
assembler <INPUT_FILE>
```

## Functions of an Assembler

The basic function of an assembler is to encode mnemonic / RISC-V instructions
into machine code that can be executed by the CPU.

Extended functions are to output the machine code in a relocateable output file
format such as (ELF, MachO or PE). This is usually stored in object files using
the file extension .o. Object files are the input to a linker.

Further extended functions are
* Filling sections with data
* Resolving Pseudo instructions to actual instructions
* Optimize instructions
* Execute assembler instructions (.include, .equ, .BYTE, .HALF, .WORD, .DWORD) (as opposed to mnemonics)
* Perform preprocessor functionality such as including files via .include
* Resolving labels into addresses and replacing the labels inside the instructions
* Executing %hi, %lo modifiers inside instructions

### Filling Sections with Data

A CPU has a consecutive address space. For microcontrollers without a
Memory Management Unit (MMU) the CPU actually works on this consecutive
address space. For CPUs with MMU, the individual applications see a virtual
consecutive address space.

When an application is executed, the executable (.elf format) specifies
where to place data into that address space so that the applcation finds
it's code and data. The loader has to check the .elf file, read all sections
and place the data into memory.

The assembler has to work towards this goal by assuming sections and placing
code into these sections.

There are the sections .text, .data, .rodata, .bss, .ascii, ...

The assembler initially uses the .text segment, which is where machine code
goes. The assembler will fill the current section byte by byte. A normal
32-bit RISC-V assembler instruction uses 32-bit (4 byte). Using the .BYTE
assembler instruction, the assembler can also place any number of bytes into
the current section (meaning it is possible to place data that is not exactly
four byte into the sections.)

### Resolving Pseudo Instructions

For convenience, often used combinations of instructions are combined into
pseudo instructions. For example a XLEN=32-bit RISC-V CPU cannot load a 32 bit
value into a register in a single step since instructions themselves are
encoded into a 32-bit word.

Therefore the 32-bit immediate is separated into a combination of lui and addi.
As the user of an assembler, the need still exists to load a 32 bit value into
a register. Therefore a li pseudo instruction exists which cannot be executed
on the CPU directly but is resolved by the assembler into lui and addi
instructions which perform the effective task and can be executed on the CPU.

It is the assembler's task to resolve pseudo instructions.

https://stackoverflow.com/questions/65006052/how-do-i-write-not-operation-for-the-risc-v-assembly-language

```
Pseudo Instruction   | Expansion                      | Function
---------------------+--------------------------------+--------------------------
nop                  | addi x0, x0, 0                 | No operation
li rd, immediate     | Myriad sequences               | Load immediate
mv rd, rs            | addi rd, rs, 0                 | Copy register
not rd, rs           | xori rd, rs, -1                | One’s complement
neg rd, rs           | sub rd, x0, rs                 | Two’s complement
negw rd, rs          | subw rd, x0, rs                | Two’s complement word
sext.w rd, rs        | addiw rd, rs, 0                | Sign extend word
seqz rd, rs          | sltiu rd, rs, 1                | Set if = zero
snez rd, rs          | sltu rd, x0, rs                | Set if ̸= zero
sltz rd, rs          | slt rd, rs, x0                 | Set if < zero
sgtz rd, rs          | slt rd, x0, rs                 | Set if > zero
beqz rs, offset      | beq rs, x0, offset             | Branch if = zero
bnez rs, offset      | bne rs, x0, offset             | Branch if ̸= zero
blez rs, offset      | bge x0, rs, offset             | Branch if ≤ zero
bgez rs, offset      | bge rs, x0, offset             | Branch if ≥ zero
bltz rs, offset      | blt rs, x0, offset             | Branch if < zero
bgtz rs, offset      | blt x0, rs, offset             | Branch if > zero
bgt rs, rt, offset   | blt rt, rs, offset             | Branch if >
ble rs, rt, offset   | bge rt, rs, offset             | Branch if ≤
bgtu rs, rt, offset  | bltu rt, rs, offset            | Branch if >, unsigned
bleu rs, rt, offset  | bgeu rt, rs, offset            | Branch if ≤, unsigned
j offset             | jal x0, offset                 | Jump
jal offset           | jal x1, offset                 | Jump and link
jr rs                | jalr x0, 0(rs)                 | Jump register
jalr rs              | jalr x1, 0(rs)                 | Jump and link register
ret                  | jalr x0, 0(x1)                 | Return from subroutine
call aa              | auipc x1, aa[31 : 12] + aa[11] | Call far-away subroutine
                     | jalr x1, aa[11:0](x1)          | (two instructions)
tail aa              | auipc x6, aa[31 : 12] + aa[11] | Tail call far-away subroutine
                     | jalr x0, aa[11:0](x6)          | (also two instructions)
```

### Optimizing Instructions

The pseudo instruction li is resolved into a combination of lui and addi.
During the resolution, the assembler will not generate lui or addi depending
on the parameters of li. If the entire parameter data is loaded by a single
lui, then no addi needs to be generated and vice versa.

The potential for optimization arises when the assembly source code contains
a lui, addi combination that was manually added. When this combination can
be transferred into a li pseudo instruction, then the assembler can optimize
that pseudo instruction in a second step according to the means described above.

The optimization step will therefore detect lui, addi combinations that can
be combined into a li pseudo instruction.

### Execute Assembler Instructions

Assembler instructions are commands such as .include, .equ, .BYTE, .HALF, .WORD, .DWORD.
They control the assembler itself.

.BYTE places a single byte into current section.


## Building

Install flex and bison. Use the Makefile to build the assembler and the emulator.

### Building and Running the Assembler

```
make assembler
```

will build the assembler.

To run the assembler, a .s file has to be provided as a command line parameter
when running the assembler:

```
assembler.exe test/resources/add.s
./assembler test/resources/add.s
```

The assembler will print the machine code to the terminal currently.

You can cross check the validity of the machine code using a online RISCV assembler:

```
https://luplab.gitlab.io/rvcodecjs/#q=add++++t1,+t0,+a0&abi=false&isa=AUTO
```

### Building and Running the Emulator

```
emulator.exe
./emulator
```

Currently the emulator cannot read ihex or elf files.

### Compiling and Running the Tests

The tests require cmocka to function.
First download and compile the cmocka libraries.

```
https://cmocka.org/files/1.1/cmocka-1.1.7.tar.xz
```

Extract this archive. After extraction, there should be a folder called cmocka-1.1.7.
Copy this folder into the test folder.

Then build the library using the install target

Linux:

```
cd test
make install
```

On windows, use the cmake-gui (CMake) to configure and create a Visual Studio project.
Once that Visual Studio project exists, you can open it in Visual Studio to build
the cmocka libraries:

Start CMake (cmake-gui) as administrator since it needs to create symlinks which is only allowed using elevated rights.
Browse source > select the folder: "test\cmocka-1.1.7\cmocka-1.1.7"
Where to build the binaries: "riscv_assembler/cmocka-build-dir"

Click the configure button
Click the generate button
Click open project and let visual studio build the source code

The .dll file is created inside: C:\Users\wolfg\dev\c\riscv_assembler\cmocka-build-dir\src\Debug

inside the cmocka-build-dir folder, create a lib and a include folder.
Copy the files cmocka.dll from C:\Users\wolfg\dev\c\riscv_assembler\cmocka-build-dir\src\Debug to C:\Users\wolfg\dev\c\riscv_assembler\test
Copy the files cmocka.lib from C:\Users\wolfg\dev\c\riscv_assembler\cmocka-build-dir\src\Debug to C:\Users\wolfg\dev\c\riscv_assembler\test\lib

ERROR:
```
CMake Error: failed to create symbolic link 'C:/Users/wolfg/dev/c/riscv_assembler/test/cmocka-1.1.7/cmocka-1.1.7/compile_commands.json': A required privilege is not held by the client.
```

SOLUTION:
Start cmake-gui using administrator rights because of symlink creation.

Once the cmocka library is compiled and available inside the test\lib folder the unit tests can be compiled.

Compile the tests

```
cd test
make
```

Next, run the cmockatest executable to run all tests.

Linux:
```
./cmockatest
```

Windows:
```
cmockatest.exe
```

At the very end of the output, theres should be a message that all tests have passed:

```
[==========] tests: 12 test(s) run.
[  PASSED  ] 12 test(s).
```




## Adding new instruction

*Pro Tip:* Before you make any changes to the application, start by
compiling and running the unit tests to see if the application currently
is in a good state or if anything is broken already before you change the code.

1. Update the lexer lexer.l (add a token that matches the instruction exactly. Add that rule before the identifier rule.)
1. Update the parser parser.y (add a new <sym> token and add the instruction to the mnemonic rule)
1. Update instruction_to_string() in asm_line.c
1. update the instruction-enum in asm_line.h (this file)
1. Update encoder.c/.h
1. Update decoder.c/.h
1. Make sure that the function determine_instruction_size() in assembler.c returns the correct size for each instruction!
1. Add test to test\unit_tests\main.c (this entails creating a new pair of .c/.h for the new test)
1. Add the test files .c/.h to test\Makefile so that they get compiled
1. Generate the lexer and the parser (only once as long as you do not change lexer.l and parser.y)
```
cd ~/dev/riscv/risc_assembler
make
```
1. Navigate into the test folder and compile the unit tests:
```
cd test
make
```
1. Run the unit tests:
```
./cmockatest
```



# Emulating a RISC V CPU

## Initializing the StackPointer

https://stackoverflow.com/questions/68645402/where-does-the-stack-pointer-start-for-risc-v-and-where-does-the-stack-pointer
https://stackoverflow.com/questions/30024660/initializing-stack-pointer

The stack pointer is initially set to a undefined value.
The register sp (stack pointer) (register x2) is used for the stack pointer.

Looking at assembly code that gcc produces, the first instruction is most times

```
addi	sp,sp,-32
```

This means that space is reserved on the stack. The application does not initialize the
stack pointer to a sensical value instead it immediately uses the stack pointer.
The application therefore expects the stack pointer to be initialized already and be ready to use.

When there is an operating system running on the RISCV CPU, it will set the stack pointer before
loading application code to execute. When there is no operating system running on the emulator then
the only correct option left is to make the emulator set a standard value into the stack pointer.

The instruction above substract 32 from the stack pointer. The stack is growing towards smaller addresses.
The stack pointer cannot be initialized to address 0x00 because after substracting 32 it would point to
non existent memory.

As a convention, the stack pointer is initially loaded with 0x880000 by the emulator because apparently
qemu does the same thing. The RISCV ABI says that the stack pointer always points to a memory cell that
is in used (It does not point to a free memory cell according to the ABI).

As the stack pointer points to a memory cell that is already used, to use
any part of the stack the first instruction has to move the stack pointer to allocate space on the stack.
Initially the stack is empty but by convention, the stack points to 0x880000 which is the first cell.
The convention says that the stack pointer always points to the last cell that is in use. Initially,
the first cell is really unused but the convention still holds, so the first cell 0x880000 will always be wasted
and will never actually be used! This is ok and works as designed.
