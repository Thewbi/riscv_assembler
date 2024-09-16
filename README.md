# riscv_assembler
RISCV assembler

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

```
cd test
make install
```

Then compile the tests

```
cd test
make
```

Next, run the cmockatest executable to run all tests.

```
./cmockatest
```

At the very end of the output, theres should be a message that all tests has passed:

```
[==========] tests: 12 test(s) run.
[  PASSED  ] 12 test(s).
```




## Adding new instruction

1. Update the lexer lexer.l (add a token that matches the instruction exactly. Add that rule before the identifier rule.)
1. Update the parser parser.y (add a new <sym> tokena and add the instruction to the mnemonic rule)
1. Update instruction_to_string() in asm_line.c
1. update the instruction-enum in asm_line.h (this file)
1. Update encoder/encoder.h
1. Update decoder/decoder.h
1. Add test to test\unit_tests\main.c
1. Add the test files .c/.h to test\Makefile so that they get compiled



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
