#include <cpu.h>

void cpu_init(cpu_t* cpu) {

    // set all registers to 0x00
    for (int i = 0; i < 32; i++) {
        cpu->reg[i] = 0x00;
    }

    // set pc to zero
    cpu->pc = 0x0000;
}

void cpu_step(cpu_t* cpu) {
    
    
    // printf("0: %d\n", (cpu->pc + 0));
    // printf("1: %d\n", (cpu->pc + 1));
    // printf("2: %d\n", (cpu->pc + 2));
    // printf("3: %d\n", (cpu->pc + 3));
    
    // printf("0: %d\n", (uint8_t)cpu->memory[(size_t)(cpu->pc + 0)]);
    // printf("1: %d\n", (uint8_t)cpu->memory[(size_t)(cpu->pc + 1)]);
    // printf("2: %d\n", (uint8_t)cpu->memory[(size_t)(cpu->pc + 2)]);
    // printf("3: %d\n", (uint8_t)cpu->memory[(size_t)(cpu->pc + 3)]);

    // printf("0: %d\n", (uint8_t)cpu->memory[0]);
    // printf("1: %d\n", (uint8_t)cpu->memory[1]);
    // printf("2: %d\n", (uint8_t)cpu->memory[2]);
    // printf("3: %d\n", (uint8_t)cpu->memory[3]);

    // uint32_t encoded_instruction = cpu->memory[(size_t)(cpu->pc + 0)] << 24 | cpu->memory[(size_t)(cpu->pc + 1)] << 16 | cpu->memory[(size_t)(cpu->pc + 2)] << 8 | cpu->memory[(size_t)(cpu->pc + 3)] << 0;
    // printf("encoded_instruction: %d\n", encoded_instruction);


    std::map<uint32_t, uint32_t *>::iterator it = cpu->segments->find(cpu->pc);
    if (it == cpu->segments->end()) {
        return;
    }
    uint32_t* text_segment = it->second;

    uint32_t encoded_instruction = text_segment[0x00];

    encoded_instruction = (((encoded_instruction >> 24) & 0xFF) << 0) | 
        (((encoded_instruction >> 16) & 0xFF) << 8) |
        (((encoded_instruction >> 8) & 0xFF) << 16) |
        (((encoded_instruction >> 0) & 0xFF) << 24);

    asm_line_t asm_line;
    reset_asm_line(&asm_line);
    decode(encoded_instruction, &asm_line);

    switch (asm_line.instruction) {

        case I_ADD:
            printf("CPU ADD detected\n");
            printf("CPU ADD rd: %d, rs1: %d, rs2: %d\n", cpu->reg[asm_line.reg_rd], cpu->reg[asm_line.reg_rs1], cpu->reg[asm_line.reg_rs2]);
            cpu->reg[asm_line.reg_rd] = cpu->reg[asm_line.reg_rs1] + cpu->reg[asm_line.reg_rs2];
            break;

        case I_ADDI:
            printf("CPU ADDI detected\n");
            printf("CPU ADDI rd: %d, rs1: %d, imm: %d\n", cpu->reg[asm_line.reg_rd], cpu->reg[asm_line.reg_rs1], asm_line.imm);
            cpu->reg[asm_line.reg_rd] = cpu->reg[asm_line.reg_rs1] + asm_line.imm;
            break;

        default:
            printf("Unknown instruction!\n");

    }

    cpu->pc += 0x04;
}