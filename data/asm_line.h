#ifndef _ASM_LINE
#define _ASM_LINE

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

#include "../common/common.h"
#include "../common/register.h"
#include "../common/node.h"

// Adding new instruction
//
// 1. Update the lexer lexer.l (add a token that matches the instruction exactly. Add that rule before the identifier rule.)
// 1. Update the parser parser.y (add a new <sym> tokena and add the instruction to the mnemonic rule)
// 1. Update instruction_to_string() in asm_line.c
// 1. update the instruction-enum in asm_line.h (this file)
//
// 1. Update encoder/encoder.h
// 1. Update decoder/decoder.h
//
// 1. Add test to test\unit_tests\main.c
// 1. Add the test files .c/.h to test\Makefile so that they get compiled
enum instruction {

    // I-Type
    I_ADDI,
    I_SRLI,
    I_SLLI,
    I_SLTI,
    I_SLTIU,
    I_XORI,
    I_ORI,
    I_ANDI,

    I_LB,
    I_LH,
    I_LW,
    I_LBU,
    I_LHU,

    // B-Type
    I_BEQ,
    I_BGE,
    I_BNE,

    // R-Type
    I_ADD,
    I_MUL,

    // S-Type
    I_SW, // store word

    // U-Type
    I_AUIPC,
    I_LUI,

    // J-Type
    I_JAL, // jump and link
    I_JALR,

    // P-Type (pseudoinstruction)
    I_BEQZ, // pseudo instruction
    I_BNEZ, // pseudo instruction
    I_CALL, // pseudo instruction
    I_J, // pseudo instruction
    I_MV, // pseudo instruction
    I_RET, // pseudo instruction
    I_LI, // pseudo instruction

    // undefined
    I_UNDEFINED_INSTRUCTION

};

enum instruction_type {

    IT_R,
    IT_I,
    IT_S,
    IT_B,
    IT_U,
    IT_J,
    IT_P, // (pseudoinstruction) you will not find P-Type in the RISC V specification!
    IT_UNDEFINED_INSTRUCTION

};

enum assembler_instruction {

    AI_EQU,
    AI_SECTION,
    AI_GLOBL,
    AI_TEXT,

    AI_UNDEFINED

};

typedef struct asm_line {

    //
    // general
    //

    uint8_t used;
    uint32_t line_nr;
    uint8_t size_in_bytes;

    //
    // Label to jump to in assembler code
    //

    char label[100];

    //
    // assembler instruction
    //

    enum assembler_instruction asm_instruction;
    char asm_instruction_symbol[100];
    node_t* asm_instruction_expr;

    //
    // mnemonic / cpu instruction
    //

    enum instruction instruction;

    enum instruction_type instruction_type;

    enum register_ reg_rd;
    enum register_ reg_rs1;
    enum register_ reg_rs2;

    uint32_t imm;

    uint32_t offset_0;
    char offset_identifier_0[100];
    uint8_t offset_0_used;
    node_t* offset_0_expression;

    uint32_t offset_1;
    char offset_identifier_1[100];
    uint8_t offset_1_used;
    node_t* offset_1_expression;

    uint32_t offset_2;
    char offset_identifier_2[100];
    uint8_t offset_2_used;
    node_t* offset_2_expression;

} asm_line_t;

/**
 * Places standard values into a asm_line.
 *
 * @param data the asm_line to reset.
 */
void reset_asm_line(asm_line_t *data);
void reset_asm_lines(asm_line_t *data, const int size);

void copy_asm_line(asm_line_t* target, asm_line_t* source);

/**
 *
 */
void insert_register(asm_line_t *data, enum register_);

/**
 *
 */
void insert_offset(asm_line_t *data, uint32_t offset, uint8_t index);
void insert_identifier_offset(asm_line_t *data, char* offset, uint8_t index);

/**
 *
 */
void insert_expr(asm_line_t *data, node_t* node, uint8_t index);

/**
 *
 */
void insert_integer_immediate(asm_line_t *data, uint32_t imm);

/**
 * Prints a asm_line using printf().
 *
 * @param data the asm_line to print.
 */
void print_asm_line(const asm_line_t *data);
void serialize_asm_line(const asm_line_t *data);

/**
 *
 */
void print_expression(const node_t* data, char* buffer);

/**
 * Converts the instruction enum to a string.
 *
 * @param data the instruction to convert.
 */
const char* instruction_to_string(enum instruction data);

const char* assembler_instruction_to_string(enum assembler_instruction data);

/**
 *
 */
const char* register_to_string(enum register_ data);

void set_instruction(asm_line_t *data, const enum instruction instr, const enum instruction_type type);

void resolve_pseudo_instructions_asm_line(asm_line_t* asm_line_array, const int size, const int index);

#endif