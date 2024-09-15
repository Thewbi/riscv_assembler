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
