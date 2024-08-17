app: parser.hpp parser.cpp lex.yy.c data\asm_line.c
	g++ -o riscv parser.cpp lex.yy.c data\asm_line.c -I data

lex.yy.c: lexer.l
	flex -d lexer.l
	
parser.hpp: parser.ypp
	bison -v --defines=parser.hpp --output=parser.cpp parser.ypp
	
.PHONY: clean

clean:
	rm -f riscv.exe parser.hpp parser.cpp lex.yy.c parser.output