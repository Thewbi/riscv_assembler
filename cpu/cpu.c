#include "cpu.h"

void cpu_init(cpu_t* cpu) {

    // set all registers to 0x00
    for (int i = 0; i < 32; i++) {
        cpu->reg[i] = 0x00;
    }

    // set pc to zero
    cpu->pc = 0x0000;

    // set the stackpointer to 0x880000
    cpu->reg[2] = 0x880000;

    cpu->segments = NULL;
}

uint32_t cpu_step(cpu_t* cpu, asm_line_t* asm_line) {

    if (execute_instruction(cpu, asm_line)) {
        return -1;
    }
    return 0;
}

uint32_t execute_instruction(cpu_t* cpu, const asm_line_t* asm_line) {

    switch (asm_line->instruction) {

        case I_ADD:
        {
            //printf("CPU ADD detected\n");
            printf("CPU ADD rd: %s (%d), rs1: %s (%d), rs2: %s (%d)\n", register_to_string(asm_line->reg_rd), cpu->reg[asm_line->reg_rd],
                register_to_string(asm_line->reg_rs1), cpu->reg[asm_line->reg_rs1],
                register_to_string(asm_line->reg_rs2), cpu->reg[asm_line->reg_rs2]);

            cpu->reg[asm_line->reg_rd] = cpu->reg[asm_line->reg_rs1] + cpu->reg[asm_line->reg_rs2];

            cpu->pc += PC_INCREMENT;
        }
        break;

        case I_ADDI:
        {
            //printf("CPU ADDI detected\n");
            printf("CPU ADDI rd: %s (%d), rs1: %s (%d), imm: %d\n", register_to_string(asm_line->reg_rd), cpu->reg[asm_line->reg_rd], register_to_string(asm_line->reg_rs1), cpu->reg[asm_line->reg_rs1], sign_extend_12_bit_to_uint32_t(asm_line->imm));

            //cpu->reg[asm_line->reg_rd] = cpu->reg[asm_line->reg_rs1] + sign_extend_12_bit_to_uint32_t(asm_line->imm);
            cpu->reg[asm_line->reg_rd] = cpu->reg[asm_line->reg_rs1] + asm_line->imm;

            cpu->pc += PC_INCREMENT;
        }
        break;

        case I_BEQ:
        {
            printf("CPU BEQ\n");

            if (cpu->reg[asm_line->reg_rs1] == cpu->reg[asm_line->reg_rs2]) {

                int32_t imm_temp = sign_extend_12_bit_to_uint32_t(asm_line->imm);
                //cpu->pc += (imm_temp  / 4);
                //cpu->pc = (imm_temp  / 4);
                cpu->pc = imm_temp;
            } else {
                cpu->pc += PC_INCREMENT;
            }
        }
        break;

        case I_BGE:
        {
            printf("CPU BGE\n");
            // printf("CPU JAL rd: %s (%d), imm: %d\n", register_to_string(asm_line->reg_rd), cpu->reg[asm_line->reg_rd],
            //     sign_extend_12_bit_to_uint32_t(asm_line->imm));

            if (cpu->reg[asm_line->reg_rs1] >= cpu->reg[asm_line->reg_rs2]) {
                //cpu->pc += (sign_extend_12_bit_to_uint32_t(asm_line->imm)/4);

                int32_t imm_temp = sign_extend_12_bit_to_uint32_t(asm_line->imm);
                cpu->pc += imm_temp;
            } else {
                cpu->pc += PC_INCREMENT;
            }
        }
        break;

        // SW = Store Word
        //
        // Description:
        // Store 32-bit value located in rs2 into the memory location at base+offset where
        // base is rs1 and offset is the immediate value
        //
        // Documentation:
        // https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf - page 19
        //
        // Format:
        // SW rs2, imm(rs1)
        // @param rs1 - base
        // @param rs2 - source
        // @param imm - offset from base
        //
        // Examples:
        // fef42423, sw a5, -24(s0)
        // 00812e23, sw s0, 28(sp)
        case I_SW:
        {
            // DEBUG
            printf("CPU SW rs1: Idx:%d, ABI-Name:%s (%d), rs2: Idx:%d, ABI-Name:%s (%d), imm: %d\n",
                asm_line->reg_rs1, register_to_string(asm_line->reg_rs1), sign_extend_12_bit_to_uint32_t(cpu->reg[asm_line->reg_rs1]),
                asm_line->reg_rs2, register_to_string(asm_line->reg_rs2), sign_extend_12_bit_to_uint32_t(cpu->reg[asm_line->reg_rs2]),
                sign_extend_12_bit_to_uint32_t(asm_line->imm));

            uint32_t address = cpu->reg[asm_line->reg_rs1] + asm_line->imm;

            // DEBUG
            printf("address: 0x%08x\n", address);

            uint32_t segment_address = address & 0xFFFF0000;
            uint32_t instr_address = address & 0x0000FFFF;

            // check if the segment is created already otherwise create it
            std::map<uint32_t, uint32_t *>::iterator it = cpu->segments->find(segment_address);
            if (it == cpu->segments->end()) {
                uint32_t* segment_ptr = new uint32_t[16384];
                memset(segment_ptr, 0, 16384);
                cpu->segments->insert(std::pair<uint32_t, uint32_t*>(segment_address, segment_ptr));
            }

            printf("[STORE_WORD] value: %d -> address: 0x%08x\n", cpu->reg[asm_line->reg_rs2], address);

            // store the source register into memory onto the stack
            cpu->segments->at(segment_address)[instr_address/4] = cpu->reg[asm_line->reg_rs2];

            cpu->pc += PC_INCREMENT;
        }
        break;

        // LB = Load Byte
        //
        // The LW instruction loads a 32-bit value from memory into rd.
        // LH loads a 16-bit value from memory, then sign-extends to 32-bits before storing in rd.
        // LHU loads a 16-bit value from memory but then zero extends to 32-bits before storing in rd.
        //
        // LB and LBU are defined analogously for 8-bit values
        // LB loads a 8-bit value from memory, then sign-extends to 32-bits before storing in rd.
        // LBU loads a 8-bit value from memory but then zero extends to 32-bits before storing in rd.
        //
        // Format:      lb rd, imm12(rs1)
        // Example:     lb t1, 123(t1)
        case I_LB:
        {
            printf("CPU LB\n");

            uint32_t address = cpu->reg[asm_line->reg_rs1] + asm_line->imm;

            // DEBUG
            printf("address: 0x%08x\n", address);

            uint32_t segment_address = address & 0xFFFF0000;
            uint32_t instr_address = address & 0x0000FFFF;

            // check if the segment is created already otherwise create it
            std::map<uint32_t, uint32_t *>::iterator it = cpu->segments->find(segment_address);
            if (it == cpu->segments->end()) {
                uint32_t* segment_ptr = new uint32_t[16384];
                memset(segment_ptr, 0, 16384);
                cpu->segments->insert(std::pair<uint32_t, uint32_t*>(segment_address, segment_ptr));
            }

            uint32_t temp_value = cpu->segments->at(segment_address)[instr_address/4];
            uint8_t temp_value_as_uint8_t = (uint8_t) temp_value & 0xFF;

            cpu->reg[asm_line->reg_rd] = sign_extend_8_bit_to_uint32_t(temp_value_as_uint8_t);

            cpu->pc += PC_INCREMENT;
        }
        break;

        // LW = Load Word
        //
        // Description:
        // The LW instruction loads a 32-bit value from memory into rd.
        //
        // Documentation:
        // https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf - page 19
        //
        // Format:
        // LW rd, imm(rs1)
        // @param rd  - dest
        // @param rs1 - base
        // @param imm - offset from base
        //
        // Examples:
        // fec42703, lw a4, -20(s0)
        // 01c12403, lw s0, 28(sp)
        case I_LW:
        {
            //printf("CPU LW detected\n");
            printf("CPU LW rd: %s (%d), rs1: %s (%d), imm: %d\n", register_to_string(asm_line->reg_rd), cpu->reg[asm_line->reg_rd], register_to_string(asm_line->reg_rs1), cpu->reg[asm_line->reg_rs1], sign_extend_12_bit_to_uint32_t(asm_line->imm));

            uint32_t address = cpu->reg[asm_line->reg_rs1] + asm_line->imm;

            // DEBUG
            printf("address: 0x%08x\n", address);

            uint32_t segment_address = address & 0xFFFF0000;
            uint32_t instr_address = address & 0x0000FFFF;

            uint32_t temp_value = cpu->segments->at(segment_address)[instr_address/4];

            printf("[LOAD_WORD] value: %d <- address: 0x%08x\n", temp_value, address);

            cpu->reg[asm_line->reg_rd] = temp_value;

            cpu->pc += PC_INCREMENT;
        }
        break;

        case I_JALR:
        {
            printf("CPU JALR rd: %s (%d), rs1: %s (%d), imm: %d\n", register_to_string(asm_line->reg_rd), cpu->reg[asm_line->reg_rd],
                register_to_string(asm_line->reg_rs1), cpu->reg[asm_line->reg_rs1],
                sign_extend_12_bit_to_uint32_t(asm_line->imm));

            // TODO implement this!!!!!
        }
        break;

        // Description:
        // The jump and link (JAL) instruction uses the J-type format, where the J-immediate encodes a
        // signed offset in multiples of 2 bytes. The offset is sign-extended and added to the pc to form the
        // jump target address.
        //
        // Examples:
        // j 40000030
        // jal x0, 28
        case I_JAL:
        {
            printf("CPU JAL rd: %s (%d), imm: %d\n", register_to_string(asm_line->reg_rd), cpu->reg[asm_line->reg_rd],
                sign_extend_12_bit_to_uint32_t(asm_line->imm));

            //cpu->pc += (asm_line->imm/4);
            //cpu->pc += (asm_line->imm / 4);
            cpu->pc += asm_line->imm;

            //cpu->pc += PC_INCREMENT;
        }
        break;

        case I_LUI:
        {
            printf("CPU LUI\n");

            // LUI (load upper immediate) places the U-immediate value in the
            // top 20 bits of the destination register rd, filling in the lowest
            // 12 bits with zeros.

            cpu->reg[asm_line->reg_rd] = 0x00;
            cpu->reg[asm_line->reg_rd] |= asm_line->imm << 12;

            cpu->pc += PC_INCREMENT;

        }
        break;

        default:
            printf("cpu::cpu_step() - Unknown instruction: %s\n", instruction_to_string(asm_line->instruction));
            return -1;

    }

    return 0;
}

uint32_t fetch_instruction_at_pc(cpu_t* cpu) {

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

    uint32_t segment_address = cpu->pc & 0xFFFF0000;
    uint32_t instr_address = cpu->pc & 0x0000FFFF;

    std::map<uint32_t, uint32_t *>::iterator it = cpu->segments->find(segment_address);
    if (it == cpu->segments->end()) {
        return 0x00;
    }
    uint32_t* text_segment = it->second;

    uint32_t encoded_instruction = text_segment[instr_address/4];

    encoded_instruction = (((encoded_instruction >> 24) & 0xFF) << 0) |
        (((encoded_instruction >> 16) & 0xFF) << 8) |
        (((encoded_instruction >> 8) & 0xFF) << 16) |
        (((encoded_instruction >> 0) & 0xFF) << 24);

    return encoded_instruction;
}
