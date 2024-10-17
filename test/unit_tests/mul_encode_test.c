#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <setjmp.h>
#include <cmocka.h>

#define YYDEBUG 1

#include "asm_line.h"
#include "parser.h"
#include "encoder.h"

extern asm_line_t parser_asm_line;

extern FILE* yyin;
extern int yy_flex_debug;

extern void (*fp_emit)(asm_line_t*);

/**
 * mul  a5,  a5,  a5
 * mul x15, x15, x15
 */
void mul_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    // printf("reset parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
    // printf("reset parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
    // printf("reset parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
    // printf("reset parser_asm_line->imm %d\n", parser_asm_line.imm);

    //fp_emit = &emit;

    yyin = fopen("resources/mul.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/mul.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    // run the parser on the input file.
    // The parser will load data into the variable parser_asm_line
    yyparse();

    // printf("parser_asm_line->instruction %d\n", parser_asm_line.instruction);
    // printf("parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
    // printf("parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
    // printf("parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
    // printf("parser_asm_line->imm %d\n", parser_asm_line.imm);
    
    uint32_t result = encode_mul(&parser_asm_line);

    // Assert

    assert_int_equal(0x02f787b3, result);
}

