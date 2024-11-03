#ifndef REGISTER
#define REGISTER

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

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

uint8_t encode_register(enum register_ data);

#endif