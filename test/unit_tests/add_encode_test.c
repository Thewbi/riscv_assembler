#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <setjmp.h>
#include <cmocka.h>

#define YYDEBUG 1

#include "asm_line.h"
#include "parser.h"

asm_line_t asm_line;

extern FILE* yyin;
extern int yy_flex_debug;

extern void (*fp_emit)(asm_line_t*);

void emit(asm_line_t* asm_line) {
    printf("emit LUL\n");
}

/* A test case that does nothing and succeeds. */
void add_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&asm_line);

    fp_emit = &emit;

    yyin = fopen("resources/add.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/add.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    yyparse();

    // Assert

    assert_int_equal(I_ADD, asm_line.instruction);
}

