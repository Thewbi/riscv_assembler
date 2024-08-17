#include <cpu.h>

void cpu_init(cpu_t* cpu) {

    for (int i = 0; i < 32; i++) {
        cpu->reg[i] = 0x00;
    }

    cpu->pc = 0x0000;

}

void cpu_step(cpu_t* cpu) {
    
    asm_line_t asm_line;
    reset_asm_line(&asm_line);

    printf("0: %d\n", (cpu->pc + 0));
    printf("1: %d\n", (cpu->pc + 1));
    printf("2: %d\n", (cpu->pc + 2));
    printf("3: %d\n", (cpu->pc + 3));
    
    printf("0: %d\n", (uint8_t)cpu->memory[(size_t)(cpu->pc + 0)]);
    printf("1: %d\n", (uint8_t)cpu->memory[(size_t)(cpu->pc + 1)]);
    printf("2: %d\n", (uint8_t)cpu->memory[(size_t)(cpu->pc + 2)]);
    printf("3: %d\n", (uint8_t)cpu->memory[(size_t)(cpu->pc + 3)]);

    printf("0: %d\n", (uint8_t)cpu->memory[0]);
    printf("1: %d\n", (uint8_t)cpu->memory[1]);
    printf("2: %d\n", (uint8_t)cpu->memory[2]);
    printf("3: %d\n", (uint8_t)cpu->memory[3]);

    uint32_t encoded_instruction = cpu->memory[(size_t)(cpu->pc + 0)] << 24 | cpu->memory[(size_t)(cpu->pc + 1)] << 16 | cpu->memory[(size_t)(cpu->pc + 2)] << 8 | cpu->memory[(size_t)(cpu->pc + 3)] << 0;
    printf("encoded_instruction: %d\n", encoded_instruction);

    decode(encoded_instruction, &asm_line);

    cpu->pc += 0x04;

    switch (asm_line.instruction) {

        case I_ADD:
            printf("CPU ADD detected\n");
            printf("CPU ADD rd: %d rs1 %d rs2 %d\n", cpu->reg[asm_line.reg_rd], cpu->reg[asm_line.reg_rs1], cpu->reg[asm_line.reg_rs2]);
            cpu->reg[asm_line.reg_rd] = cpu->reg[asm_line.reg_rs1] + cpu->reg[asm_line.reg_rs2];
            break;

        default:
            printf("Unknown instruction!\n");

    }
}