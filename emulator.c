#include <asm_line.h>
#include <ihex_loader.h>
#include <cpu.h>

asm_line_t parser_asm_line;

int main(int argc, char **argv)
{
    // // asm_line_t asm_line;
    // // reset_asm_line(&asm_line);

    // // asm_line.instruction = I_ADD;
    // // asm_line.reg_rd = R_T0;
    // // asm_line.reg_rs1 = R_T1;
    // // asm_line.reg_rs2 = R_T2;

    // uint8_t memory[1024];
    // for (int i = 0; i < 1024; i++) {
    //     memory[i] = 0x00;
    // }

    // // https://www.eg.bucknell.edu/~csci206/riscv-converter/index.html
    // // add    t1, t0, a0  == 0x00A28333 = 0000000 01010 00101 000 00110 0110011
    // memory[0] = 0x00;
    // memory[1] = 0xA2;
    // memory[2] = 0x83;
    // memory[3] = 0x33;

    // // addi    t0, t0, 15  == 0x00F28293 = 000000001111 00101 000 00101 0010011
    // memory[0] = 0x00;
    // memory[1] = 0xF2;
    // memory[2] = 0x82;
    // memory[3] = 0x93;

    std::string ihex_file = "test/resources/example.hex";

    IHexLoader ihex_loader;
    ihex_loader.load_ihex_file(ihex_file);
    ihex_loader.debug_output(0x20);

    cpu_t cpu;
    cpu_init(&cpu);
    cpu.pc = ihex_loader.start_address;

    
    //cpu.memory = memory;
    cpu.segments = &(ihex_loader.segments);
    

    // // DEBUG
    // cpu.reg[R_T0] = 2;
    // cpu.reg[R_A0] = 3;

    cpu_step(&cpu);

    //printf("REG R_T0: %d\n", cpu.reg[R_T0]);
    //printf("REG R_T1: %d\n", cpu.reg[R_T1]);

    return 0;
}