// #include <stdarg.h>
// #include <stddef.h>
// #include <stdint.h>

// #include <setjmp.h>
// #include <cmocka.h>

// #define YYDEBUG 1

// #include "asm_line.h"
// #include "parser.h"
// #include "encoder.h"

// extern asm_line_t parser_asm_line;

// extern FILE* yyin;
// extern int yy_flex_debug;

// extern void (*fp_emit)(asm_line_t*);

// /**
//  * mv (move) is a pseudoinstruction. It is implemented using:
//  * mv rd, rs --> addi rd, rs, 0
//  * mv a0, a5 --> addi a0, a5, 0
//  */
// void mv_encode_valid_input_test(void **state)
// {
//     // Arrange

//     reset_asm_line(&parser_asm_line);

//     // printf("reset parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
//     // printf("reset parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
//     // printf("reset parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
//     // printf("reset parser_asm_line->imm %d\n", parser_asm_line.imm);

//     //fp_emit = &emit;

//     yyin = fopen("resources/mv.s", "r");
//     if (!yyin) {
//         printf("Cannot open '%s'. Aborting.\n", "resources/mv.s");
//     }

//     yy_flex_debug = 0;
//     yydebug = 0;

//     // Act

//     // run the parser on the input file.
//     // The parser will load data into the variable parser_asm_line
//     yyparse();

//     // printf("parser_asm_line->instruction %d\n", parser_asm_line.instruction);
//     // printf("parser_asm_line->reg_rd %d\n", parser_asm_line.reg_rd);
//     // printf("parser_asm_line->reg_rs1 %d\n", parser_asm_line.reg_rs1);
//     // printf("parser_asm_line->reg_rs2 %d\n", parser_asm_line.reg_rs2);
//     // printf("parser_asm_line->imm %d\n", parser_asm_line.imm);

//     uint32_t result = encode_mv(&parser_asm_line);

//     // Assert

//     assert_int_equal(0x00078513, result);
// }

