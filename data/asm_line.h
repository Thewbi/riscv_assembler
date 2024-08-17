#ifndef _ASM_LINE
#define _ASM_LINE

//#include <cstdio>
#include <stdio.h>

enum instruction {
    I_ADD,
    I_UNDEFINED_INSTRUCTION
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

    // enum register_ reg_1;
    // enum register_ reg_2;
    // enum register_ reg_3;

    enum register_ reg_rd;
    enum register_ reg_rs1;
    enum register_ reg_rs2;

} asm_line_t;

/**
 * Places standard values into a asm_line.
 * 
 * @param data the asm_line to reset.
 */
void reset_asm_line(asm_line_t *data);

void insert_register(asm_line_t *data, enum register_);

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

#endif