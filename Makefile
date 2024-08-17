app: parser.hpp parser.c lex.yy.c data\asm_line.c
	g++ -o riscv parser.c lex.yy.c data\asm_line.c -I data

lex.yy.c: lexer.l
	flex -d lexer.l
	
parser.hpp: parser.ypp
	bison -v --defines=parser.h --output=parser.c parser.ypp
	
.PHONY: clean

clean:
	rm -f riscv.exe parser.h parser.c lex.yy.c parser.output