#include <asm_line.h>
#include <ihex_loader.h>
#include <assembler.h>
#include <cpu.h>

//#define BUILD_ASSEMBLER 1
#define BUILD_EMULATOR 1

#define USE_HEX_FILE 0
#define USE_ASSEMBLER_SOURCE_FILE 1

//#define DBUILD_EMULATOR 1
//#ifdef DBUILD_EMULATOR

int main(int argc, char **argv)
{

#ifdef BUILD_ASSEMBLER
    uint32_t machine_code[100];
    memset(machine_code, 0, 100);

    assemble(argv[1], machine_code);

    return 0;
#endif

#ifdef BUILD_EMULATOR

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

#if USE_HEX_FILE

    std::string ihex_file = "test/resources/add_example.hex";
    //std::string ihex_file = "test/resources/loop_example.hex";
    //std::string ihex_file = "test/resources/loop_example_2.hex";
    //std::string ihex_file = "test/resources/string_length.hex";

    IHexLoader ihex_loader;
    ihex_loader.load_ihex_file(ihex_file);
    ihex_loader.debug_output(0x20);

    cpu_t cpu;
    cpu_init(&cpu);
    cpu.pc = ihex_loader.start_address;

    //cpu.memory = memory;
    cpu.segments = &(ihex_loader.segments);

#endif

#if USE_ASSEMBLER_SOURCE_FILE

    cpu_t cpu;
    cpu_init(&cpu);
    cpu.pc = 0x00;

    std::map<uint32_t, uint32_t*> segments;
    cpu.segments = &segments;

    //std::string source_file = "test/resources/label_and_instruction.s";
    //std::string source_file = "test/resources/string_length.s";
    //std::string source_file = "test/resources/add3.s";
    //std::string source_file = "test/resources/blinker.s";
    //std::string source_file = "test/resources/loads.s";
    std::string source_file = "test/resources/scratchpad.s";

    uint32_t machine_code[100];
    memset(machine_code, 0, 100);

    assemble(source_file.c_str(), machine_code, &segments);
    printf("\n\n");

#endif

    // // DEBUG
    // cpu.reg[R_T0] = 2;
    // cpu.reg[R_A0] = 3;

    cpu.reg[R_A1] = 2;
    cpu.reg[R_A2] = 3;

    asm_line_t* asm_line_ptr = NULL;

    for (int i = 0; i < 100; i++) {

        printf("[cpu_step()] pc: 0x%08x\n", cpu.pc);

#if USE_HEX_FILE
        uint32_t encoded_instruction = fetch_instruction_at_pc(cpu);
        asm_line_t asm_line;
        asm_line_ptr = &asm_line;
        reset_asm_line(&asm_line);
        decode(encoded_instruction, &asm_line);
#endif

#if USE_ASSEMBLER_SOURCE_FILE
        uint32_t encoded_instruction = machine_code[cpu.pc/4];
        asm_line_t asm_line;
        asm_line_ptr = &asm_line;
        reset_asm_line(&asm_line);
        decode(encoded_instruction, &asm_line);
#endif

        if (asm_line_ptr->used == 0) {
            printf("Unused line encountered! Aborting CPU\n");
            break;
        }
        if (cpu_step(&cpu, asm_line_ptr)) {
            printf("CPU could not execute instruction! Aborting CPU\n");
            break;
        }

    }

    //printf("REG R_T0: %d\n", cpu.reg[R_T0]);
    //printf("REG R_T1: %d\n", cpu.reg[R_T1]);

    //printf("REG R_T1: %d\n", cpu.reg[R_A0]);
    printf("REG R_GP: %d\n", cpu.reg[R_GP]);
    printf("REG R_GP: 0x%08" PRIx64 "\n", cpu.reg[R_GP]);
    printf("REG R_SP: 0x%08" PRIx64 "\n", cpu.reg[R_SP]);

    return 0;

#endif
}

//#endif