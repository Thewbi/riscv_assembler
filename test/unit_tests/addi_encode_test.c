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

void addi_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    //fp_emit = &emit;

    yyin = fopen("resources/addi.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/addi.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    // run the parser on the input file.
    // The parser will load data into the variable parser_asm_line
    yyparse();

    uint32_t result = encode_addi(&parser_asm_line);

    // Assert

    //printf("Test-I_ADDI: %d Test-instr: %d\n", I_ADDI, parser_asm_line.instruction);
    //printf("Test-I_ADDI: 0x%08x\n", result);

    // assert_int_equal(I_ADDI, parser_asm_line.instruction);
    // assert_int_equal(15, parser_asm_line.imm);
    // assert_int_equal(R_T0, parser_asm_line.reg_rd);
    // assert_int_equal(R_T0, parser_asm_line.reg_rs1);

    assert_int_equal(0x00F28293, result);
}

