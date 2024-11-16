#ifndef CPU
#define CPU

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <map>
#include <vector>

#include "../data/asm_line.h"
#include "../decoder/decoder.h"

#define PC_INCREMENT 0x04

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

    //uint16_t pc;
    uint32_t pc;

    //uint8_t* memory;

    std::map<uint32_t, uint32_t*>* segments;

} cpu_t;

void cpu_init(cpu_t* cpu);

uint32_t cpu_step(cpu_t* cpu, asm_line_t* asm_line);

uint32_t fetch_instruction_at_pc(cpu_t* cpu);

uint32_t execute_instruction(cpu_t* cpu, const asm_line_t* asm_line);

#endif