#ifndef _ASM_LINE
#define _ASM_LINE

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Adding new instruction
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

    
    I_LI,
    I_JALR,
    
    // R-Type
    I_ADD,

    // S-Type
    I_SW,

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
    IT_UNDEFINED_INSTRUCTION
};

// cannot use name register since it is a reserved keyword in C
// https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf - page 109
enum register_ {

  R_ZERO, // 0, Hard-wired zero
  R_RA, // 1, Return address
  R_SP, // 2, Stack pointer
  R_GP, // 3, Global pointer
  R_TP, // 4, Thread pointer
  R_T0, // 5, Temporary/alternate link register
  R_T1, // 6, Temporary
  R_T2, // 7, Temporary
  R_S0, // 8, Saved register/frame pointer
  R_S1, // 9, Saved register
  R_A0, // 10, Function arguments/return values
  R_A1, // 11, Function arguments/return values
  R_A2, // 12, Function arguments
  R_A3, // 13, Function arguments
  R_A4, // 14, Function arguments
  R_A5, // 15, Function arguments
  R_A6, // 16, Function arguments
  R_A7, // 17, Function arguments
  R_S2, // 18, Saved registers
  R_S3, // 19, Saved registers
  R_S4, // 20, Saved registers
  R_S5, // 21, Saved registers
  R_S6, // 22, Saved registers
  R_S7, // 23, Saved registers
  R_S8, // 24, Saved registers
  R_S9, // 25, Saved registers
  R_S10, // 26, Saved registers
  R_S11, // 27, Saved registers
  R_T3, // 28, Temporary
  R_T4, // 29, Temporary
  R_T5, // 30, Temporary
  R_T6, // 31, Temporary
  
  R_UNDEFINED_REGISTER

};

typedef struct asm_line {

    enum instruction instruction;

    enum instruction_type instruction_type;

    enum register_ reg_rd;
    enum register_ reg_rs1;
    enum register_ reg_rs2;

    uint16_t imm;

    uint16_t offset_0;
    uint16_t offset_1;
    uint16_t offset_2;

    uint8_t offset_0_used;
    uint8_t offset_1_used;
    uint8_t offset_2_used;

} asm_line_t;

/**
 * Places standard values into a asm_line.
 * 
 * @param data the asm_line to reset.
 */
void reset_asm_line(asm_line_t *data);

/**
 * 
 */
void insert_register(asm_line_t *data, enum register_);

/**
 * 
 */
void insert_offset(asm_line_t *data, uint32_t offset, uint8_t index);

/**
 * 
 */
void insert_integer_immediate(asm_line_t *data, uint16_t imm);

/**
 * Prints a asm_line using printf().
 * 
 * @param data the asm_line to print.
 */
void print_asm_line(const asm_line_t *data);

/**
 * Converts the instruction enum to a string.
 * 
 * @param data the instruction to convert.
 */
const char* instruction_to_string(enum instruction data);

/**
 * 
 */
const char* register_to_string(enum register_ data);

#endif