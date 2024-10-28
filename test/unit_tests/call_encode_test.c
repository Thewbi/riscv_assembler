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
 * call 0x0BFFFC00
 */
void call_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    // printf("reset parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
    // printf("reset parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
    // printf("reset parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
    // printf("reset parser_asm_line->imm %d\n", parser_asm_line.imm);

    //fp_emit = &emit;

    yyin = fopen("resources/call.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/call.s");
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
    
    uint32_t output_buffer[2];
    encode_call(&parser_asm_line, output_buffer);

    // Assert

    // auipc x6, 0x0BFFF -> 0x0bfff317
    assert_int_equal(0x0bfff317, output_buffer[0]);

    // jalr x0, 0xC00(x6) -> 0xc0030067
    assert_int_equal(0xc0030067, output_buffer[1]);
}

