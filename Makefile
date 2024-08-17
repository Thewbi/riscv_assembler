app: parser.h parser.c lex.yy.c data\asm_line.h data\asm_line.c encoder\encoder.h encoder\encoder.c
	g++ -o riscv parser.c lex.yy.c data\asm_line.c encoder\encoder.c -I data -I encoder

lex.yy.c: lexer.l
	flex -d lexer.l
	
parser.h: parser.y
	bison -v --defines=parser.h --output=parser.c parser.y
	
.PHONY: clean

clean:
	rm -f riscv.exe parser.h parser.c lex.yy.c parser.output