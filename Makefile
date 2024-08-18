assembler: parser.h parser.c lex.yy.c data\asm_line.h data\asm_line.c encoder\encoder.h encoder\encoder.c
	g++ -o assembler parser.c lex.yy.c data\asm_line.c encoder\encoder.c -I data -I encoder

emulator: emulator.c parser.h parser.c lex.yy.c data\asm_line.h data\asm_line.c encoder\encoder.h encoder\encoder.c encoder\decoder.h encoder\decoder.c cpu\cpu.h cpu\cpu.c
	g++ -o emulator emulator.c parser.c lex.yy.c data\asm_line.c encoder\encoder.c decoder\decoder.c cpu\cpu.c -I data -I encoder -I decoder -I cpu

lex.yy.c: lexer.l
	flex -d lexer.l
	
parser.h: parser.y
	bison -v --defines=parser.h --output=parser.c parser.y
	
.PHONY: clean

clean:
	rm -f riscv.exe parser.h parser.c lex.yy.c parser.output