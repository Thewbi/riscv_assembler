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
 * https://stackoverflow.com/questions/65979263/assembly-what-is-ret
 *
 * pseudo instruction ret
 * ret -> jalr x0, 0(x1)
 */
void ret_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    // printf("reset parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
    // printf("reset parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
    // printf("reset parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
    // printf("reset parser_asm_line->imm %d\n", parser_asm_line.imm);

    //fp_emit = &emit;

    yyin = fopen("resources/ret.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/ret.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    // run the parser on the input file.
    // The parser will load data into the variable parser_asm_line
    yyparse();

    // printf("parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
    // printf("parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
    // printf("parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
    // printf("parser_asm_line->imm %d\n", parser_asm_line.imm);
    // printf("parser_asm_line->imm %08" PRIx32 "\n", parser_asm_line.imm);

    uint32_t result = encode_ret(&parser_asm_line);

    // Assert

    // jalr x0, 0(x1) -> 00008067
    assert_int_equal(0x00008067, result);
}

