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
 * SRLI rd, rs1, IMM [I-type]
 * srli s1, s5, 17
 */
void srli_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    //fp_emit = &emit;

    yyin = fopen("resources/srli.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/srli.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    // run the parser on the input file.
    // The parser will load data into the variable parser_asm_line
    yyparse();

    // parser_asm_line.instruction = I_SRLI;
    // parser_asm_line.imm = 17;
    // parser_asm_line.reg_rs1 = R_S5;
    // parser_asm_line.reg_rd = R_S1;
    uint32_t result = encode_srli(&parser_asm_line);

    // Assert

    //printf("Test-I_SRLI: %d Test-instr: %d\n", I_SRLI, parser_asm_line.instruction);
    //printf("Test-I_SRLI: 0x%08x\n", result);

    // assert_int_equal(I_SRLI, parser_asm_line.instruction);
    // assert_int_equal(17, parser_asm_line.imm);
    // assert_int_equal(R_S1, parser_asm_line.reg_rd);
    // assert_int_equal(R_S5, parser_asm_line.reg_rs1);

    assert_int_equal(0x011ad493, result);
}

