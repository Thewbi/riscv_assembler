#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <setjmp.h>
#include <cmocka.h>

#define YYDEBUG 1

#include "asm_line.h"
#include "parser.h"
#include "encoder.h"

// this asm_line is used inside the parser as workspace.
// It is declared as an external variable within the parser which
// means the driver has to provide the real variable by declaring
// it.
asm_line_t parser_asm_line;

extern FILE* yyin;
extern int yy_flex_debug;

extern void (*fp_emit)(asm_line_t*);

/* A test case that does nothing and succeeds. */
void add_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    //fp_emit = &emit;

    yyin = fopen("resources/add.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/add.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    // run the parser on the input file.
    // The parser will load data into the variable parser_asm_line
    yyparse();

    uint32_t result = encode_add(&parser_asm_line);

    // Assert

    //assert_int_equal(I_ADD, parser_asm_line.instruction);

    assert_int_equal(0x00a28333, result);
}

