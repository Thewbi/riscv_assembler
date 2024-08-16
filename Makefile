app: parser.hpp parser.cpp lex.yy.c
	g++ -o riscv parser.cpp lex.yy.c

lex.yy.c:
	flex parser.l
	
parser.hpp: parser.ypp
	bison -v --defines=parser.hpp --output=parser.cpp parser.ypp
	
.PHONY: clean

clean:
	rm -f riscv.exe parser.hpp parser.cpp lex.yy.c parser.output