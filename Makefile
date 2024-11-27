.PHONY: all
all: parser.h lex.yy.c emulator

# to user the parser as a standalone executable (without a driver application),
# edit parser.y and activate the #define USE_INTERNAL_DRIVER 1 line
# The parser will then use it's own asm_line_t parser_asm_line variable internally (and not externally)

# Build the assembler.
# The assembler.c acts as a driver to the parser and therefore deactivate the #define USE_INTERNAL_DRIVER 1 line in parser.c
assembler: assembler.c \
	parser.h \
	parser.c \
	lex.yy.c \
	data/asm_line.h \
	data/asm_line.c \
	encoder/encoder.h \
	encoder/encoder.c \
	preprocessor/preprocessor.h \
	preprocessor/preprocessor.c \
	common/common.c \
	common/common.h \
	common/register.h \
	common/register.c \
	common/node.h \
	common/node.c \
	container\trivial_map\trivial_map.h \
	container\trivial_map\trivial_map.c \
	container\tuple_set\tuple_set.h \
	container\tuple_set\tuple_set.c
	g++ -g -o assembler \
	assembler.c \
	parser.c \
	lex.yy.c \
	data/asm_line.c \
	encoder/encoder.c \
	common/common.c \
	common/register.c \
	common/node.c \
	container\trivial_map\trivial_map.c \
	container\tuple_set\tuple_set.c -I ./ -I common -I container -I data -I encoder

# Build the emulator.
# The emulator does not use the parser as it does not execute from .s files but only from assembled machine code.
# Use the assembler application to produce machine code from .s files first.
emulator: common/common.c \
	common/common.h \
	common/register.h \
	common/register.c \
	common/node.h \
	common/node.c \
	preprocessor/preprocessor.h \
	preprocessor/preprocessor.c \
	container\trivial_map\trivial_map.h \
	container\trivial_map\trivial_map.c \
	container\tuple_set\tuple_set.h \
	container\tuple_set\tuple_set.c \
	emulator.c \
	assembler.h \
	assembler.c \
	parser.h \
	parser.c \
	lex.yy.c \
	data/asm_line.h \
	data/asm_line.c \
	encoder/encoder.h \
	encoder/encoder.c \
	decoder/decoder.h \
	decoder/decoder.c \
	ihex_loader/ihex_loader.h \
	ihex_loader/ihex_loader.cpp \
	cpu/cpu.h \
	cpu/cpu.c
	g++ -g -o emulator \
	common/common.c \
	common/register.c \
	common/node.c \
	preprocessor/preprocessor.c \
	container/trivial_map/trivial_map.c \
	container/tuple_set/tuple_set.c \
	emulator.c \
	assembler.c \
	parser.c \
	lex.yy.c \
	data/asm_line.c \
	encoder/encoder.c \
	decoder/decoder.c \
	ihex_loader/ihex_loader.cpp \
	cpu/cpu.c -I ./ -I common -I container -I data -I encoder -I decoder -I cpu -I ihex_loader

lex.yy.c: lexer.l
	flex -d lexer.l

parser.h: parser.y
	bison -v --defines=parser.h --output=parser.c parser.y

.PHONY: clean

clean:
	rm -f emulator assembler emulator.exe riscv.exe parser.h parser.c lex.yy.c parser.output