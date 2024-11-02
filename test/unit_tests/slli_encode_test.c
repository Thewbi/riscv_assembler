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
 * SLLI rd, rs1, IMM [I-type]
 * slli s1, s1, 2
 */
void slli_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    yyin = fopen("resources/slli.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/slli.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    // run the parser on the input file.
    // The parser will load data into the variable parser_asm_line
    yyparse();

    //print_asm_line(&parser_asm_line);

    //printf("A\n");
    assert_int_equal(9, parser_asm_line.reg_rd);

    //printf("B\n");
    assert_int_equal(9, parser_asm_line.reg_rs1);

    //printf("C\n");
    assert_int_equal(2, parser_asm_line.offset_2_expression->int_val);
    //assert_int_equal(2, parser_asm_line.imm);
    //printf("D\n");

    //printf("parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
    //printf("parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
    //printf("parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
    //printf("parser_asm_line->imm %d\n", parser_asm_line.imm);
    //printf("parser_asm_line->imm %08" PRIx32 "\n", parser_asm_line.imm);

    uint32_t result = encode_slli(&parser_asm_line);

    // Assert

    assert_int_equal(0x00249493, result);
}

