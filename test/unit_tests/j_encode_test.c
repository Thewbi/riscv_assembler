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
 * j 0xBFFF00
 */
void j_encode_valid_input_test(void **state)
{
    // Arrange

    reset_asm_line(&parser_asm_line);

    // printf("reset parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
    // printf("reset parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
    // printf("reset parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
    // printf("reset parser_asm_line->imm %d\n", parser_asm_line.imm);

    //fp_emit = &emit;

    yyin = fopen("resources/j.s", "r");
    if (!yyin) {
        printf("Cannot open '%s'. Aborting.\n", "resources/j.s");
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
    encode_j(&parser_asm_line, output_buffer);

    // Assert

    // auipc x5, 0x03000  -> 03000297
    assert_int_equal(0x03000297, output_buffer[0]);

    // jalr x0, 0xc00(x5) -> 0xc0028067          
    assert_int_equal(0xc0028067, output_buffer[1]);
}

