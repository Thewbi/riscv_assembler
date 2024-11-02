#include <stdio.h>

#include <asm_line.h>
#include <encoder.h>
#include <parser.h>
#include <node.h>

asm_line_t parser_asm_line;

extern FILE* yyin;
extern int yy_flex_debug;
extern int yydebug;

// https://www.geeksforgeeks.org/function-pointer-in-c/
//
// fp_emit() which stands for function pointer emit() is provided
// by the encoder. The parser will parse mnemonics from the .s file,
// write data into the parser_asm_line variable that the driver
// provides and it will then call fp_emit() to pass the parser_asm_line
// variable to the module that provided fp_emit().
//
// In the case of this application, the encoder is the module that provides
// fp_emit(). The encoder will encode the parser_asm_line variable to
// machine code and print the machine code to the console.
extern void (*fp_emit)(asm_line_t*);

extern int asm_line_array_index;
extern asm_line_t asm_line_array[100];

int main(int argc, char **argv)
{
    reset_asm_line(&parser_asm_line);

    fp_emit = &encoder_callback;

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", argv[1]);
    }

    yy_flex_debug = 0;
    yydebug = 0;
    yyparse();

    printf("asm_lines: %d\n", asm_line_array_index);

    for (int i = 0; i < asm_line_array_index; i++) {

        printf("line %d\n", i);
        print_asm_line(&asm_line_array[i]);
    }

    return 0;
}