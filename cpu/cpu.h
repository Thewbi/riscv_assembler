#ifndef CPU
#define CPU

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include <asm_line.h>
#include <decoder.h>

// https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf - page 9
//
// Figure 2.1 shows the user-visible state for the base integer subset. There are 31 general-purpose
// registers x1–x31, which hold integer values. Register x0 is hardwired to the constant 0. There is
// no hardwired subroutine return address link register, but the standard software calling convention
// uses register x1 to hold the return address on a call. For RV32, the x registers are 32 bits wide,
// and for RV64, they are 64 bits wide. This document uses the term XLEN to refer to the current
// width of an x register in bits (either 32 or 64).
//
typedef struct cpu {

    uint32_t reg[32];

    uint16_t pc;

    uint8_t* memory;

} cpu_t;

void cpu_init(cpu_t* cpu);

void cpu_step(cpu_t* cpu);

#endif