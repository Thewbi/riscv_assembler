.PHONY: all
all: parser.h lex.yy.c assembler emulator

# to user the parser as a standalone executable (without a driver application), 
# edit parser.y and activate the #define USE_INTERNAL_DRIVER 1 line
# The parser will then use it's own asm_line_t parser_asm_line variable internally (and not externally)

# Build the assembler. 
# The assembler.c acts as a driver to the parser and therefore deactivate the #define USE_INTERNAL_DRIVER 1 line in parser.c
assembler: assembler.c parser.h parser.c lex.yy.c data/asm_line.h data/asm_line.c encoder/encoder.h encoder/encoder.c
	g++ -o assembler assembler.c parser.c lex.yy.c data/asm_line.c encoder/encoder.c -I ./ -I data -I encoder

# Build the emulator. 
# The emulator does not use the parser as it does not execute from .s files but only from assembled machine code.
# Use the assembler application to produce machine code from .s files first.
emulator: emulator.c parser.h parser.c lex.yy.c data/asm_line.h data/asm_line.c encoder/encoder.h encoder/encoder.c decoder/decoder.h decoder/decoder.c cpu/cpu.h cpu/cpu.c
	g++ -o emulator emulator.c parser.c lex.yy.c data/asm_line.c encoder/encoder.c decoder/decoder.c cpu/cpu.c -I data -I encoder -I decoder -I cpu

lex.yy.c: lexer.l
	flex -d lexer.l
	
parser.h: parser.y
	bison -v --defines=parser.h --output=parser.c parser.y
	
.PHONY: clean

clean:
	rm -f riscv.exe parser.h parser.c lex.yy.c parser.output