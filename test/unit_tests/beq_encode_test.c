#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <setjmp.h>
#include <cmocka.h>

#define YYDEBUG 1

#include "beq_encode_test.h"

extern asm_line_t parser_asm_line;

extern FILE* yyin;
extern int yy_flex_debug;

extern void (*fp_emit)(asm_line_t*);

/**
 * BEQ rd, rs1, IMM [B-type]
 * beq x8, x9, 16
 */
void beq_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    yyin = fopen("resources/beq.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/beq.s");
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
    

    uint32_t result = encode_beq(&parser_asm_line);

    // Assert

    assert_int_equal(0x00940863, result);
}

