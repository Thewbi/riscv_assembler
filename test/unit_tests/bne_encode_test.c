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

void bne_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    // printf("encode_b_type opcode: %d \n", parser_asm_line.instruction);
    // printf("encode_b_type rs1: %d \n", parser_asm_line.reg_rs1);
    // printf("encode_b_type rs2: %d \n", parser_asm_line.reg_rs2);
    // printf("encode_b_type rd: %d \n", parser_asm_line.reg_rd);
    // printf("encode_b_type imm: %d \n", parser_asm_line.imm);

    //fp_emit = &emit;

    yyin = fopen("resources/bne.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/bne.s");
    }

    yy_flex_debug = 0;
    yydebug = 0;

    // Act

    // run the parser on the input file.
    // The parser will load data into the variable parser_asm_line
    yyparse();

    // printf("encode_b_type opcode: %d \n", parser_asm_line.instruction);
    // printf("encode_b_type rs1: %d \n", parser_asm_line.reg_rs1);
    // printf("encode_b_type rs2: %d \n", parser_asm_line.reg_rs2);
    // printf("encode_b_type rd: %d \n", parser_asm_line.reg_rd);
    // printf("encode_b_type imm: %d \n", parser_asm_line.imm);

    uint32_t result = encode_bne(&parser_asm_line);

    // Assert

    //printf("Test-I_ADDI: %d Test-instr: %d\n", I_ADDI, parser_asm_line.instruction);
    //printf("Test-I_ADDI: 0x%08x\n", result);

    // assert_int_equal(I_ADDI, parser_asm_line.instruction);
    // assert_int_equal(15, parser_asm_line.imm);
    // assert_int_equal(R_T0, parser_asm_line.reg_rd);
    // assert_int_equal(R_T0, parser_asm_line.reg_rs1);

    assert_int_equal(0x07de1263, result);

    // addi    a0,a0,-273
    //assert_int_equal(0xeef50513, result);
}

