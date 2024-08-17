#ifndef _ASM_LINE
#define _ASM_LINE

//#include <cstdio>
#include <stdio.h>

enum instruction {
    I_ADD,
    I_UNDEFINED_INSTRUCTION
};

// cannot use name register since it is a reserved keyword in C
enum register_ {

  R_ZERO, // 0
  R_RA, // 1
  R_SP, // 2
  R_GP, // 3
  R_TP, // 4
  R_T0, // 5
  R_T1, // 6
  R_T2, // 7
  R_S0, // 8
  R_FP, // 9
  R_A0,  // 10
  
  R_UNDEFINED_REGISTER

};

typedef struct asm_line {

    enum instruction instruction;

    enum register_ reg_1;
    enum register_ reg_2;
    enum register_ reg_3;

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