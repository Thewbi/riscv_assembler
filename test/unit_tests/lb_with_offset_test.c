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

void ld_with_offset_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    //fp_emit = &emit;

    yyin = fopen("resources/lb_with_offset.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/lb_with_offset.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    yyparse();

    //uint32_t result = encode_addi(&parser_asm_line);

    // Assert

    //printf("Test-I_ADDI: %d Test-instr: %d\n", I_ADDI, parser_asm_line.instruction);

    assert_int_equal(I_LB, parser_asm_line.instruction);

    assert_false(parser_asm_line.offset_0_used);
    assert_int_equal(0, parser_asm_line.offset_0);
    assert_int_equal(R_T1, parser_asm_line.reg_rd);

    assert_true(parser_asm_line.offset_1_used);
    assert_int_equal(123, parser_asm_line.offset_1);
    assert_int_equal(R_T1, parser_asm_line.reg_rs1);

    assert_false(parser_asm_line.offset_2_used);
    assert_int_equal(0, parser_asm_line.offset_2);
    assert_int_equal(R_UNDEFINED_REGISTER, parser_asm_line.reg_rs2);

    //assert_int_equal(0x00F28293, result);
}

