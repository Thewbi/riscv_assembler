#include "asm_line.h"

void reset_asm_line(asm_line_t *data) {

    //printf("reset\n");

    //
    // general
    //

    data->used = 0;
    data->line_nr = 0;
    data->instruction_index = -1;

    //
    // Label to jump to in assembler code
    //

    memset(data->label, 0, 100);

    //
    // assembler instruction
    //

    data->asm_instruction = AI_UNDEFINED;
    memset(data->asm_instruction_symbol, 0, 100);
    data->asm_instruction_expr = NULL;

    //
    // mnemonic / cpu instruction
    //

    data->instruction = I_UNDEFINED_INSTRUCTION;
    data->instruction_type = IT_UNDEFINED_INSTRUCTION;

    data->reg_rd = R_UNDEFINED_REGISTER;
    data->reg_rs1 = R_UNDEFINED_REGISTER;
    data->reg_rs2 = R_UNDEFINED_REGISTER;

    data->imm = 0;

    data->offset_0 = 0;
    data->offset_1 = 0;
    data->offset_2 = 0;

    data->offset_0_used = 0;
    data->offset_1_used = 0;
    data->offset_2_used = 0;

    data->offset_0_expression = NULL;
    data->offset_1_expression = NULL;
    data->offset_2_expression = NULL;

    memset(data->offset_identifier_0, 0, 100);
    memset(data->offset_identifier_1, 0, 100);
    memset(data->offset_identifier_2, 0, 100);

    data->parameter_modifier_0 = PM_UNDEFINED;
    data->parameter_modifier_1 = PM_UNDEFINED;
    data->parameter_modifier_2 = PM_UNDEFINED;

}

void reset_asm_lines(asm_line_t *data, const int size) {
    for (int i = 0; i < size; i++) {
        reset_asm_line(&data[i]);
    }
}

void copy_asm_line(asm_line_t* target, asm_line_t* source) {

    //printf("copy\n");

    //
    // general
    //

    target->used = source->used;
    target->line_nr = source->line_nr;
    target->instruction_index = source->instruction_index;
    //target->size_in_bytes = source->size_in_bytes;

    //
    // Label to jump to in assembler code
    //

    memset(target->label, 0, 100);
    memcpy(target->label, source->label, 100);

    //
    // assembler instruction
    //

    target->asm_instruction = source->asm_instruction;

    memset(target->asm_instruction_symbol, 0, 100);
    memcpy(target->asm_instruction_symbol, source->asm_instruction_symbol, 100);

    target->asm_instruction_expr = source->asm_instruction_expr;

    //
    // mnemonic / cpu instruction
    //

    target->instruction = source->instruction;
    target->instruction_type = source->instruction_type;

    target->reg_rd = source->reg_rd;
    target->reg_rs1 = source->reg_rs1;
    target->reg_rs2 = source->reg_rs2;

    target->imm = source->imm;

    target->offset_0 = source->offset_0;
    memcpy(target->offset_identifier_0, source->offset_identifier_0, 100);
    target->offset_0_used = source->offset_0_used;
    target->offset_0_expression = source->offset_0_expression; // TODO: deep copy?
    target->parameter_modifier_0 = source->parameter_modifier_0;

    target->offset_1 = source->offset_1;
    memcpy(target->offset_identifier_1, source->offset_identifier_1, 100);
    target->offset_1_used = source->offset_1_used;
    target->offset_1_expression = source->offset_1_expression; // TODO: deep copy?
    target->parameter_modifier_1 = source->parameter_modifier_1;

    target->offset_2 = source->offset_2;
    memcpy(target->offset_identifier_2, source->offset_identifier_2, 100);
    target->offset_2_used = source->offset_2_used;
    target->offset_2_expression = source->offset_2_expression; // TODO: deep copy?
    target->parameter_modifier_2 = source->parameter_modifier_2;
}

void print_asm_line(const asm_line_t *data) {

    if (data->asm_instruction != AI_UNDEFINED) {

        char buffer_3[100];

        memset(buffer_3, 0, 100);

        print_expression(data->asm_instruction_expr, buffer_3);

        printf("[(%d) AssemblerInstr: Label:%s Instr:%s Symbol:%s Val: %s]\n",
            data->line_nr,
            data->label,
            assembler_instruction_to_string(data->asm_instruction),
            data->asm_instruction_symbol, buffer_3);

    } else {

        char buffer_0[100];
        char buffer_1[100];
        char buffer_2[100];

        memset(buffer_0, 0, 100);
        memset(buffer_1, 0, 100);
        memset(buffer_2, 0, 100);

        print_expression(data->offset_0_expression, buffer_0);
        print_expression(data->offset_1_expression, buffer_1);
        print_expression(data->offset_2_expression, buffer_2);

        printf("[(%d) InstrIdx: %d Label: %s, Instr: %s Imm: %d Used: %d \n \
    0:{offset_0_used:%d offset:%d offset_ident:%s register:%s offset_0_expr:%s modifier:%s}\n \
    1:{offset_1_used:%d offset:%d offset_ident:%s register:%s offset_1_expr:%s modifier:%s}\n \
    2:{offset_2_used:%d offset:%d offset_ident:%s register:%s offset_2_expr:%s modifier:%s}\n \
]\n",
            data->line_nr,
            data->instruction_index,
            data->label,
            instruction_to_string(data->instruction),
            data->imm,
            data->used,
            data->offset_0_used, data->offset_0, data->offset_identifier_0, register_to_string(data->reg_rd), buffer_0, print_parameter_modifier(data->parameter_modifier_0),
            data->offset_1_used, data->offset_1, data->offset_identifier_1, register_to_string(data->reg_rs1), buffer_1, print_parameter_modifier(data->parameter_modifier_1),
            data->offset_2_used, data->offset_2, data->offset_identifier_2, register_to_string(data->reg_rs2), buffer_2, print_parameter_modifier(data->parameter_modifier_2));

    }

}

void output_offset(const asm_line_t *data) {
    if (data->offset_0_used) {
        printf("0x%08" PRIx32 "", data->offset_0);
    }
    else if (data->offset_1_used) {
        printf("0x%08" PRIx32 "", data->offset_1);
    }
    else if (data->offset_2_used) {
        printf("0x%08" PRIx32 "", data->offset_2);
    }
    else if (data->offset_2_expression != NULL) {
        printf("0x%08" PRIx32 "", data->offset_2_expression->int_val);
    } else {
        printf("0x%08" PRIx32 "", data->imm);
    }
}

void serialize_asm_line(const asm_line_t *data) {

    if (data->asm_instruction != AI_UNDEFINED) {

        // nop

    } else {

        printf("%s ", instruction_to_string(data->instruction));

        switch (data->instruction) {

            // I-Type
            case I_ADDI:
            case I_ADDIW:
            case I_SRLI:
            case I_SLLI:
            case I_SLTI:
            case I_SLTIU:
            case I_XORI:
            case I_ORI:
            case I_ANDI:
                printf("%s, ", register_to_string(data->reg_rd));
                printf("%s, ", register_to_string(data->reg_rs1));
                if (data->offset_2_expression != NULL) {
                    printf("0x%08" PRIx32 "", data->offset_2_expression->int_val);
                } else {
                    printf("0x%08" PRIx32 "", data->imm);
                }
                break;

            // S-Type
            case I_LB:
            case I_LH:
            case I_LW:
            case I_LD:
            case I_LBU:
            case I_LHU: {
                printf("%s, ", register_to_string(data->reg_rd));
                printf("0x%08" PRIx32 "", data->imm);
                enum register_ reg = data->reg_rs1;
                if (reg == R_UNDEFINED_REGISTER) {
                    reg = R_ZERO;
                }
                printf("(%s)", register_to_string(reg));
                }
                break;

            // B-Type
            case I_BEQ:
            case I_BGE:
            case I_BLT:
            case I_BNE:
            case I_LI:
                if (data->reg_rd != R_UNDEFINED_REGISTER) {
                    printf("%s, ", register_to_string(data->reg_rd));
                }
                if (data->reg_rs1 != R_UNDEFINED_REGISTER) {
                    printf("%s, ", register_to_string(data->reg_rs1));
                }
                if (data->reg_rs2 != R_UNDEFINED_REGISTER) {
                    printf("%s, ", register_to_string(data->reg_rs2));
                }
                output_offset(data);
                break;

            // R-Type
            case I_ADD:
            case I_MUL:
                printf("%s, ", register_to_string(data->reg_rd));
                printf("%s, ", register_to_string(data->reg_rs1));
                printf("%s ", register_to_string(data->reg_rs2));
                break;

            // S-Type
            case  I_SB: // store byte
            case  I_SH: // store half-word
            case  I_SW: // store word
            case  I_SD: // store double-word
                printf("%s, ", register_to_string(data->reg_rs2));
                output_offset(data);
                printf("(%s)", register_to_string(data->reg_rs1));
                break;

            // U-Type
            case I_AUIPC:
            case I_LUI:
                printf("%s, ", register_to_string(data->reg_rd));
                if (data->offset_1_expression != NULL) {
                    printf("0x%08" PRIx32 "", data->offset_1_expression->int_val);
                } else {
                    printf("0x%08" PRIx32 "", data->imm);
                }
                break;

            // J-Type
            case I_JAL: // jump and link (pseudo instruction j is implemented via jal)
                printf("%s, ", register_to_string(data->reg_rd));
                printf("0x%08" PRIx32 "", data->imm);
                break;
            case I_JALR:
                printf("%s, ", register_to_string(data->reg_rd));
                //printf("%s, ", register_to_string(data->reg_rs1));
                //printf("%08" PRIx32 "", data->imm);
                printf("0x%08" PRIx32 "", data->imm);
                printf("(%s)", register_to_string(data->reg_rs1));
                break;

            // // P-Type (pseudoinstruction)
            // I_BNEZ, // pseudo instruction (I_BNEZ -> )
            // I_CALL, // pseudo instruction
            // I_J, // pseudo instruction
            // I_MV, // pseudo instruction
            // I_RET, // pseudo instruction

            // // undefined
            // I_UNDEFINED_INSTRUCTION
        }

        printf("\n");
    }
}

void print_expression(const node_t* data, char* buffer) {

    //printf("print_expression A %d\n", data);

    if (data == NULL) {

        //printf("print_expression B\n");

        strncpy(buffer, "NULL", 100);
        return;
    }

    //printf("print_expression x\n");
    //printf("print_expression x %d\n", data->string_val[0]);
    int val = strnlen(data->string_val, 100);
    //printf("print_expression y %d\n", val);

    if (strlen(data->string_val) != 0) {

        //printf("print_expression C\n");

        strncpy(buffer, data->string_val, strlen(data->string_val));
        return;
    }

    //printf("print_expression D\n");

    //printf("0x%" PRIx64 "", data->int_val);

    snprintf(buffer, 100, "0x%" PRIx64 "", data->int_val);
}

void insert_register(asm_line_t *data, enum register_ reg) {

    if (data->instruction_type == IT_S) {

        if (R_UNDEFINED_REGISTER == data->reg_rs2) {
            data->reg_rs2 = reg;
            return;
        }

        if (R_UNDEFINED_REGISTER == data->reg_rs1) {
            data->reg_rs1 = reg;
            return;
        }

    } else if (data->instruction_type == IT_B) {

        if (R_UNDEFINED_REGISTER == data->reg_rs1) {
            data->reg_rs1 = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs2) {
            data->reg_rs2 = reg;
            return;
        }

    } else {

        if (R_UNDEFINED_REGISTER == data->reg_rd) {
            data->reg_rd = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs1) {
            data->reg_rs1 = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs2) {
            data->reg_rs2 = reg;
            return;
        }

    }

    printf("insert_register() failure, no register found! \n");
}

void insert_offset(asm_line_t *data, uint32_t offset, uint8_t index) {

    //printf("ASM_LINE: insert_offset - offset_value: %d offset_index: %d\n", offset, index);
    switch(index) {
        case 0: data->offset_0 = offset; data->offset_0_used = 1; break;
        case 1: data->offset_1 = offset; data->offset_1_used = 1; break;
        case 2: data->offset_2 = offset; data->offset_2_used = 1; break;
        default:
            break;
    }
}

void insert_identifier_offset(asm_line_t *data, char* offset, uint8_t index) {

    // printf("insert_identifier_offset \n");
    // printf("insert_identifier_offset %s \n", offset);

    // for B and S instruction type, the rd register (index 0) is not used.
    // Therefore increment the index so that index 1 and 2 are used.
    if (data->instruction_type == IT_B || data->instruction_type == IT_S) {
        index++;
    }

    switch(index) {

        case 0: {

            //data->offset_identifier_0 = offset;
            memcpy(data->offset_identifier_0, offset, strnlen(offset, 100));
            data->offset_0_used = 1;
        }
        break;

        case 1: {
            //data->offset_identifier_1 = offset;
            memcpy(data->offset_identifier_1, offset, strnlen(offset, 100));
            data->offset_1_used = 1;
        }
        break;

        case 2: {
            //data->offset_identifier_2 = offset;
            memcpy(data->offset_identifier_2, offset, strnlen(offset, 100));
            data->offset_2_used = 1;
        }
        break;

        default:
            break;
    }
}

void insert_expr(asm_line_t *data, node_t* node, uint8_t index) {

    //printf("insert_expr - string_val: %s\n", node->string_val);
    // printf("insert_expr current_node: %d \n", node);
    // if (node != NULL) {
    //     printf("test %s \n", node->string_val);
    // }

    switch (index) {

        case 0:
            data->offset_0_expression = node;
            break;

        case 1:
            data->offset_1_expression = node;
            break;

        case 2:
            data->offset_2_expression = node;
            break;

        default:
            break;
    }

}

void insert_integer_immediate(asm_line_t *data, uint32_t imm) {

    if (data->instruction == I_LI || data->instruction == I_J || data->instruction == I_CALL) {

        // DEBUG
        //printf("ASM_LINE LI: insert_integer_immediate: %d\n", imm);
        //printf("ASM_LINE LI: 0x%" PRIx64 "\n", imm);
        //printf("ASM_LINE LI: %08" PRIx32 "\n", imm);
        data->imm = imm;

        return;
    }

    // DEBUG
    //printf("ASM_LINE: insert_integer_immediate: %d\n", imm);

    uint32_t sign_extended = sign_extend_20_bit_to_uint32_t(imm);
    data->imm = sign_extended;
}

void insert_modifier(asm_line_t *data, char* modifier, uint8_t index) {

    printf("insert_modifier: %s index: %d \n", modifier);

    enum parameter_modifier parameter_modifier_temp = PM_UNDEFINED;

    if (strncmp(modifier, "HI", 2) == 0) {
        parameter_modifier_temp = PM_HI;
    } else if (strncmp(modifier, "LO", 2) == 0) {
        parameter_modifier_temp = PM_LO;
    }

    switch(index) {
        case 0: data->parameter_modifier_0 = parameter_modifier_temp;  break;
        case 1: data->parameter_modifier_1 = parameter_modifier_temp;  break;
        case 2: data->parameter_modifier_2 = parameter_modifier_temp;  break;
        default:
            break;
    }

}

const char* instruction_to_string(enum instruction data) {

    if (data == I_UNDEFINED_INSTRUCTION) {
        return "I_UNDEFINED_INSTRUCTION";
    }

    int uppercase = 0;

    if (uppercase) {

        switch (data) {

            case I_ADD: return "ADD";
            case I_ADDI: return "ADDI";
            case I_ADDIW: return "ADDIW"; // part of RV64I
            case I_AND: return "AND";
            case I_ANDI: return "ANDI";
            case I_AUIPC: return "AUIPC";

            case I_BEQ: return "BEQ";
            case I_BEQZ: return "BEQZ"; // pseudo instruction
            case I_BGE: return "BGE";
            case I_BLT: return "BLT";
            case I_BNEZ: return "BNEZ";
            case I_BNE: return "BNE";

            case I_CALL: return "CALL"; // pseudo instruction

            case I_J: return "J"; // pseudo instruction
            case I_JR: return "JR"; // pseudo instruction
            case I_JAL: return "JAL";
            case I_JALR: return "JALR";

            case I_LD: return "LD";
            case I_LW: return "LW";
            case I_LH: return "LH";
            case I_LB: return "LB";
            case I_LBU: return "LBU";
            case I_LHU: return "LHU";
            case I_LI: return "LI"; // pseudo instruction
            case I_LUI: return "LUI";

            case I_MUL: return "MUL";
            case I_MV: return "MV"; // pseudo instruction

            case I_NOP: return "NOP"; // pseudo instruction
            case I_NOT: return "NOT"; // pseudo instruction

            case I_ORI: return "ORI";

            case I_RET: return "RET";

            case I_SLLI: return "SLLI";
            case I_SRLI: return "SRLI";
            case I_SLTIU: return "SLTIU";
            case I_SD: return "SD";
            case I_SW: return "SW";
            case I_SH: return "SH";
            case I_SB: return "SB";

            case I_WFI: return "WFI";

            case I_XORI: return "XORI";

            default: {
                return "UNKNOWN";
            }

        }
    } else {

        switch (data) {

            case I_ADD: return "add";
            case I_ADDI: return "addi";
            case I_ADDIW: return "addiw"; // part of RV64I
            case I_AND: return "and";
            case I_ANDI: return "andi";
            case I_AUIPC: return "auipc";

            case I_BEQ: return "beq";
            case I_BEQZ: return "beqz"; // pseudo instruction
            case I_BGE: return "bge";
            case I_BLT: return "blt";
            case I_BNEZ: return "bnez";
            case I_BNE: return "bne";

            case I_CALL: return "call"; // pseudo instruction

            case I_J: return "j"; // pseudo instruction
            case I_JR: return "jr"; // pseudo instruction
            case I_JAL: return "jal";
            case I_JALR: return "jalr";

            case I_LD: return "ld";
            case I_LW: return "lw";
            case I_LH: return "lh";
            case I_LB: return "lb";
            case I_LBU: return "lbu";
            case I_LHU: return "lhu";
            case I_LI: return "li"; // pseudo instruction
            case I_LUI: return "lui";

            case I_MUL: return "mul";
            case I_MV: return "mv"; // pseudo instruction

            case I_NOP: return "nop"; // pseudo instruction
            case I_NOT: return "not"; // pseudo instruction

            case I_ORI: return "ori";

            case I_RET: return "ret";

            case I_SLLI: return "slli";
            case I_SRLI: return "srli";
            case I_SLTIU: return "sltiu";
            case I_SD: return "sd";
            case I_SW: return "sw";
            case I_SH: return "sh";
            case I_SB: return "sb";

            case I_WFI: return "wfi";

            case I_XORI: return "xori";

            default: {
                return "UNKNOWN";
            }

        }

    }
}

const char* assembler_instruction_to_string(enum assembler_instruction data) {

    switch (data) {

        case AI_EQU: return "EQU";
        case AI_SECTION: return "SECTION";
        case AI_GLOBL: return "GLOBL";
        case AI_TEXT: return "TEXT";
        case AI_DATA: return "DATA";
        case AI_BYTE: return "BYTE";
        case AI_HALF: return "HALF";
        case AI_WORD: return "WORD";
        case AI_DWORD: return "DWORD";
        case AI_FILE: return "FILE";
        case AI_ASCIZ: return "ASCIZ";
        case AI_SKIP: return "SKIP";
        case AI_STRING: return "STRING";

        default: return "UNKNOWN ASSEMBLER INSTRUCTION!";
    }
}

const char* register_to_string(enum register_ data) {

    int outputABIName = 1;
    if (outputABIName) {

        switch (data) {
            case R_ZERO: return "zero"; // 0, Hard-wired zero
            case R_RA: return "ra"; // 1, Return address
            case R_SP: return "sp"; // 2, Stack pointer
            case R_GP: return "gp"; // 3, Global pointer
            case R_TP: return "tp"; // 4, Thread pointer
            case R_T0: return "t0"; // 5, Temporary/alternate link register
            case R_T1: return "t1"; // 6, Temporary
            case R_T2: return "t2"; // 7, Temporary
            case R_S0: return "fp"; // 8, Saved register/frame pointer
            case R_S1: return "s1"; // 9, Saved register
            case R_A0: return "a0"; // 10, Function arguments/return values
            case R_A1: return "a1"; // 11, Function arguments/return values
            case R_A2: return "a2"; // 12, Function arguments
            case R_A3: return "a3"; // 13, Function arguments
            case R_A4: return "a4"; // 14, Function arguments
            case R_A5: return "a5"; // 15, Function arguments
            case R_A6: return "a6"; // 16, Function arguments
            case R_A7: return "a7"; // 17, Function arguments
            case R_S2: return "s2"; // 18, Saved registers
            case R_S3: return "s3"; // 19, Saved registers
            case R_S4: return "s4"; // 20, Saved registers
            case R_S5: return "s5"; // 21, Saved registers
            case R_S6: return "s6"; // 22, Saved registers
            case R_S7: return "s7"; // 23, Saved registers
            case R_S8: return "s8"; // 24, Saved registers
            case R_S9: return "s9"; // 25, Saved registers
            case R_S10: return "s10"; // 26, Saved registers
            case R_S11: return "s11"; // 27, Saved registers
            case R_T3: return "t3"; // 28, Temporary
            case R_T4: return "t4"; // 29, Temporary
            case R_T5: return "t5"; // 30, Temporary
            case R_T6: return "t6"; // 31, Temporary

            default: return "R_UNDEFINED_REGISTER";
        }

    } else {

        switch(data) {
            case R_ZERO: return "x0"; // 0, Hard-wired zero
            case R_RA: return "x1"; // 1, Return address
            case R_SP: return "x2"; // 2, Stack pointer
            case R_GP: return "x3"; // 3, Global pointer
            case R_TP: return "x4"; // 4, Thread pointer
            case R_T0: return "x5"; // 5, Temporary/alternate link register
            case R_T1: return "x6"; // 6, Temporary
            case R_T2: return "x7"; // 7, Temporary
            case R_S0: return "x8"; // 8, Saved register/frame pointer
            case R_S1: return "x9"; // 9, Saved register
            case R_A0: return "x10"; // 10, Function arguments/return values
            case R_A1: return "x11"; // 11, Function arguments/return values
            case R_A2: return "x12"; // 12, Function arguments
            case R_A3: return "x13"; // 13, Function arguments
            case R_A4: return "x14"; // 14, Function arguments
            case R_A5: return "x15"; // 15, Function arguments
            case R_A6: return "x16"; // 16, Function arguments
            case R_A7: return "x17"; // 17, Function arguments
            case R_S2: return "x18"; // 18, Saved registers
            case R_S3: return "x19"; // 19, Saved registers
            case R_S4: return "x20"; // 20, Saved registers
            case R_S5: return "x21"; // 21, Saved registers
            case R_S6: return "x22"; // 22, Saved registers
            case R_S7: return "x23"; // 23, Saved registers
            case R_S8: return "x24"; // 24, Saved registers
            case R_S9: return "x25"; // 25, Saved registers
            case R_S10: return "x26"; // 26, Saved registers
            case R_S11: return "x27"; // 27, Saved registers
            case R_T3: return "x28"; // 28, Temporary
            case R_T4: return "x29"; // 29, Temporary
            case R_T5: return "x30"; // 30, Temporary
            case R_T6: return "x31"; // 31, Temporary

            default: return "R_UNDEFINED_REGISTER";
        }

    }
}

const char* print_parameter_modifier(const enum parameter_modifier data) {

    switch (data) {

        case PM_HI:
            return "%hi";

        case PM_LO:
            return "%LO";

        default:
            return "PM_UNDEFINED";
    }
}

// called by the parser, when a mnemonic is parsed
void set_instruction(asm_line_t *data, const enum instruction instr, const enum instruction_type type) {
    data->instruction = instr;
    data->instruction_type = type;
}

void resolve_pseudo_instructions_asm_line(asm_line_t* asm_line_array, const int size, const int index) {

    if (index >= size) {
        return;
    }

    asm_line_t* data = &asm_line_array[index];

    switch (data->instruction) {

        case I_J: {

            int line_nr = data->line_nr;

            uint32_t imm_int_val = 0;
            if (data->offset_0_used) {
                imm_int_val = data->offset_0;
            }

            // Plain unconditional jumps (assembler pseudo-op J) are encoded as a JAL with rd=x0
            asm_line_t jal;
            reset_asm_line(&jal);
            jal.used = 1;
            jal.line_nr = line_nr;
            jal.instruction = I_JAL;
            jal.instruction_type = IT_J;
            jal.instruction_index = data->instruction_index;
            jal.reg_rd = R_ZERO;
            jal.reg_rs1 = R_ZERO;
            jal.imm = imm_int_val;

            jal.offset_0_used = data->offset_0_used;
            jal.offset_0 = data->offset_0;
            jal.offset_1_used = data->offset_1_used;
            jal.offset_1 = data->offset_1;
            jal.offset_2_used = data->offset_2_used;
            jal.offset_2 = data->offset_2;

            reset_asm_line(data);
            copy_asm_line(data, &jal);
        }
        break;

        case I_JR: {

            int line_nr = data->line_nr;

            // uint32_t imm_int_val = 0;
            // if (data->offset_0_used) {
            //     imm_int_val = data->offset_0;
            // }

            // Plain unconditional jumps (assembler pseudo-op J) are encoded as a JAL with rd=x0
            asm_line_t jalr;
            reset_asm_line(&jalr);
            jalr.used = 1;
            jalr.line_nr = line_nr;
            jalr.instruction = I_JALR;
            jalr.instruction_type = IT_I;
            jalr.instruction_index = data->instruction_index;
            jalr.reg_rd = R_ZERO;
            jalr.reg_rs1 = data->reg_rs1;
            jalr.imm = 0;

            jalr.offset_0_used = data->offset_0_used;
            jalr.offset_0 = data->offset_0;
            jalr.offset_1_used = data->offset_1_used;
            jalr.offset_1 = data->offset_1;
            jalr.offset_2_used = data->offset_2_used;
            jalr.offset_2 = data->offset_2;

            reset_asm_line(data);
            copy_asm_line(data, &jalr);
        }
        break;

        case I_BEQZ: {

            int line_nr = data->line_nr;

            uint32_t imm_int_val = 0;
            if (data->offset_0_used) {
                imm_int_val = data->offset_0;
            }
            if (data->offset_1_used) {
                imm_int_val = data->offset_1;
            }
            if (data->offset_2_used) {
                imm_int_val = data->offset_2;
            }

            asm_line_t beq;
            reset_asm_line(&beq);
            beq.used = 1;
            beq.line_nr = line_nr;
            beq.instruction = I_BEQ;
            beq.instruction_type = IT_B;
            beq.instruction_index = data->instruction_index;
            beq.reg_rs1 = data->reg_rd;
            beq.reg_rs2 = R_ZERO;


            int32_t relative_offset = imm_int_val;
            beq.imm = relative_offset;

            reset_asm_line(data);
            copy_asm_line(data, &beq);

        }
        break;

        case I_CALL: {

            // when to generate a jal instruction instead of a auipc, jalr combination ?
            //
            // The official specification (https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf)
            // says on page 110, table 20.2 that a call instruction is resolved by auipc, jalr
            //
            // jal
            // The jump and link (JAL) instruction uses the J-type format, where the J-immediate encodes a
            // signed offset in multiples of 2 bytes. The offset is sign-extended and added to the pc to form the
            // jump target address. Jumps can therefore target a ±1 MiB range. JAL stores the address of the
            // instruction following the jump (pc+4) into register rd. The standard software calling convention
            // uses x1 as the return address register and x5 as an alternate link register.

            int line_nr = data->line_nr;

            uint32_t imm_int_val = 0;
            if (data->offset_0_used) {
                imm_int_val = data->offset_0;
            }

            uint32_t data_0 = (imm_int_val & 0xFFFFF000) >> 12;
            uint32_t data_1 = (imm_int_val & 0xFFF);

            if (data_0 == 0) {

                printf("CALL: Short jump detected\n");

                // Plain unconditional jumps (assembler pseudo-op J) are encoded as a JAL with rd=x0
                asm_line_t jal;
                reset_asm_line(&jal);
                jal.used = 1;
                jal.line_nr = line_nr;
                jal.instruction = I_JAL;
                jal.instruction_type = IT_J;
                jal.instruction_index = data->instruction_index;
                jal.reg_rd = R_RA;
                jal.reg_rs1 = R_ZERO;

                //int32_t relative_offset = data_1 - ((data->instruction_index + 0) * 4);
                int32_t relative_offset = data_1;
                jal.imm = relative_offset;

                // jal.offset_0_used = data->offset_0_used;
                // jal.offset_0 = data->offset_0;
                // jal.offset_1_used = data->offset_1_used;
                // jal.offset_1 = data->offset_1;
                // jal.offset_2_used = data->offset_2_used;
                // jal.offset_2 = data->offset_2;

                jal.offset_0_used = 0;
                jal.offset_0 = 0;
                jal.offset_1_used = 0;
                jal.offset_1 = 0;
                jal.offset_2_used = 0;
                jal.offset_2 = 0;

                copy_asm_line(data, &jal);

            } else {

                // TODO: search for a register that is really free
                enum register_ free_temp_register = R_T1; // x6

                //
                // auipc
                //

                uint32_t imm = data_0;

                asm_line_t auipc;
                reset_asm_line(&auipc);
                auipc.used = 1;
                auipc.line_nr = line_nr;
                auipc.instruction = I_AUIPC;
                auipc.instruction_type = IT_U;
                auipc.instruction_index = data->instruction_index;
                auipc.reg_rd = free_temp_register;
                auipc.imm = imm;

                //
                // jalr
                //

                uint8_t rs1 = encode_register(free_temp_register);
                imm = data_1;

                asm_line_t jalr;
                reset_asm_line(&jalr);
                jalr.used = 1;
                jalr.line_nr = line_nr + 1;
                jalr.instruction = I_JALR;
                jalr.instruction_type = IT_J;
                jalr.instruction_index = data->instruction_index + 1;
                jalr.reg_rd = R_ZERO;
                jalr.reg_rs1 = free_temp_register;
                jalr.imm = imm;

                reset_asm_line(data);

                for (int i = size-1; i > index; i--) {
                    copy_asm_line(&asm_line_array[i+1], &asm_line_array[i]);
                    asm_line_array[i+1].line_nr++;

                    if (asm_line_array[i + 1].instruction_index != -1) {
                        asm_line_array[i + 1].instruction_index++;
                    }
                }

                copy_asm_line(data, &auipc);
                copy_asm_line(&asm_line_array[index+1], &jalr);

            }
        }
        break;

        case I_LB:
        case I_LH: {

            // The lb instruction is not a pseudo instruction but the
            // assembler contains a convenience feature to make the life
            // of the developer easier. The assembler ammends an auipc
            // to take care of immediate values larger than imm12
            //
            // The lb instruction natively only works with an imm12 value.
            // example:
            // lb t1, 123(t1) --> lb t1, 123(t1)
            //
            // if the imm value is larger than 0xFFF the assembler can generate
            // a sequence of auipc and lb
            // example:
            // lb a0, 0xcc0000 --> lb a0, 0xcc0000(zero) --> auipc a0, 0xcc0
            //                                               lb	a0, 0x0000(a0)
            //
            // Remember: auipc rd, imm <=> rd <-- pc + (imm << 12)
            //
            // this sequence loads part of the immediate into the rs1 register
            // if the entire immediate value does not fit into 12 bits.
            //if (data->offset_1_expression->int_val > 0xFFF) {
            if (data->offset_1 > 0xFFF) {

                int line_nr = data->line_nr;

                //
                // auipc
                //

                asm_line_t auipc;
                reset_asm_line(&auipc);
                auipc.used = 1;
                auipc.line_nr = line_nr;
                auipc.instruction = I_AUIPC;
                auipc.instruction_type = IT_U;
                auipc.instruction_index = data->instruction_index;
                auipc.reg_rd = data->reg_rd;
                auipc.imm = (data->offset_1_expression->int_val >> 12);

                // modify rs1 register
                data->reg_rs1 = data->reg_rd;

                for (int i = (size-1); i >= index; i--) {

                    copy_asm_line(&asm_line_array[i + 1], &asm_line_array[i]);
                    asm_line_array[i + 1].line_nr++;

                    if (asm_line_array[i + 1].instruction_index != -1) {
                        asm_line_array[i + 1].instruction_index++;
                    }
                }

                asm_line_t* next_data = &asm_line_array[index + 1];

                next_data->imm = next_data->offset_1_expression->int_val & 0xFFF;

                // adjust the immediate value of the lb instruction
                next_data->offset_1_expression->int_val = 0x00;

                reset_asm_line(data);
                copy_asm_line(data, &auipc);
            }
        }
        break;

        case I_LI: {

            int line_nr = data->line_nr;

            // // take the 32 bit value (data_0)
            // uint32_t data_0 = 0;

            // if (data->offset_0_used) {
            //     data_0 = data->offset_1;
            // } else {
            //     data_0 = data->offset_1_expression->int_val;
            // }

            uint32_t data_0 = retrieve_immediate_part(data);

            // split it into a 20 bit (upper_data) and a lower twelve bit part (is ignored)
            uint32_t upper_data = ((data_0 & 0b11111111111111111111000000000000) >> 12);
            //printf("upper_data: %08" PRIx32 "\n", upper_data);

            uint32_t lower_data = data_0 & 0xFFF;
            //printf("lower_data: %08" PRIx32 "\n", lower_data);

            int upper_part_used = upper_data;
            int lower_part_used = lower_data;

            if (upper_part_used == 0 && lower_part_used == 0) {

                // Case 0: addi to fill entire 32bit register with zero

                //
                // addi
                //

                uint8_t rd = encode_register(data->reg_rd);
                uint8_t rs1 = encode_register(data->reg_rd);
                uint32_t imm = 0x00;

                asm_line_t addi;
                reset_asm_line(&addi);
                addi.used = 1;
                addi.line_nr = line_nr + 1;
                addi.instruction = I_ADDI;
                addi.instruction_type = IT_I;
                addi.instruction_index = data->instruction_index + 1;
                addi.reg_rd = data->reg_rd;
                addi.reg_rs1 = R_ZERO;
                addi.imm = imm;

                copy_asm_line(data, &addi);

            } else if (upper_part_used == 0 && lower_part_used != 0) {

                // Case 1: CONSTANT fits into 12 lower bits.
                // For CASE 1, a addi instruction is generated since addi handles 12 bit sufficiently

                data->instruction = I_ADDI;
                data->reg_rs1 = R_ZERO;

            } else if (upper_part_used != 0 && lower_part_used == 0) {

                // Case 2: CONSTANT fits into the 20 upper bits.

                //
                // lui - LUI (load upper immediate) is used to build 32-bit constants and uses the U-type format. LUI
                // places the U-immediate value in the top 20 bits of the destination register rd, filling in the lowest
                // 12 bits with zeros.
                //

                uint8_t rd = encode_register(data->reg_rd);
                uint32_t imm = upper_data;

                asm_line_t lui;
                reset_asm_line(&lui);
                lui.used = 1;
                lui.line_nr = line_nr;
                lui.instruction = I_LUI;
                lui.instruction_type = IT_U;
                lui.instruction_index = data->instruction_index;
                lui.reg_rd = data->reg_rd;
                lui.imm = imm;

                copy_asm_line(data, &lui);

            } else {

                // CASE 3 For CASE 3, a LUI, ADDI combination is generated so
                // that the upper 20 bits and the lower 20 bits are used

                // the 20 bit part is incremented by 1, (then shifted left by 12 bits to get (data_2))
                //data_1 = data_1 + 1;

                int32_t twelve_bit_sign_extended = sign_extend_12_bit_to_int32_t(data_0);
                int udata = data_0 - twelve_bit_sign_extended;
                udata = udata >> 12;

                // // if the lower 12 bits have a 1 in the most signifiant bit, output an optimized sequence
                // if ((lower_data & 0x08) > 0) {

                // }

                //
                // lui - LUI (load upper immediate) is used to build 32-bit constants and uses the U-type format. LUI
                // places the U-immediate value in the top 20 bits of the destination register rd, filling in the lowest
                // 12 bits with zeros.
                //

                uint8_t rd = encode_register(data->reg_rd);
                uint32_t imm = udata;

                asm_line_t lui;
                reset_asm_line(&lui);
                lui.used = 1;
                lui.line_nr = line_nr;
                lui.instruction = I_LUI;
                lui.instruction_type = IT_U;
                lui.instruction_index = data->instruction_index;
                lui.reg_rd = data->reg_rd;
                lui.imm = imm;

                copy_asm_line(data, &lui);

                //
                // addi
                //

                rd = encode_register(data->reg_rd);
                uint8_t rs1 = encode_register(data->reg_rd);
                imm = lower_data;

                asm_line_t addi;
                reset_asm_line(&addi);
                addi.used = 1;
                addi.line_nr = line_nr + 1;
                addi.instruction = I_ADDIW;
                addi.instruction_type = IT_I;
                addi.instruction_index = data->instruction_index + 1;
                addi.reg_rd = data->reg_rd;
                addi.reg_rs1 = data->reg_rd;
                addi.imm = imm;

                reset_asm_line(data);

                for (int i = size-1; i > index; i--) {
                    //printf("index: %d\n", (i > index));
                    //printf("copy %d <- %d\n", i+1, i);
                    copy_asm_line(&asm_line_array[i + 1], &asm_line_array[i]);
                    asm_line_array[i + 1].line_nr++;

                    if (asm_line_array[i + 1].instruction_index != -1) {
                        asm_line_array[i + 1].instruction_index++;
                    }
                }

                copy_asm_line(data, &lui);
                copy_asm_line(&asm_line_array[index + 1], &addi);

            }
        }
        break;

        case I_BNEZ: {
            // the I_BNEZ pseudo instruction is converted to the I_BNE instruction
            // bnez rs, offset => bne rs, x0, offset
            // see: https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
            data->instruction = I_BNE;
            data->instruction_type = IT_I;
            data->reg_rs1 = data->reg_rd;
            //data->reg_rs2 = data->reg_rd;
            data->reg_rs2 = R_ZERO;
            data->imm = 0;
        }
        break;

        case I_BGT: {
            // the I_BNEZ pseudo instruction is converted to the I_BNE instruction
            // bnez rs, offset => bne rs, x0, offset
            // see: https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
            data->instruction = I_BLT;
            data->instruction_type = IT_B;
            enum register_ temp = data->reg_rs1;
            data->reg_rs1 = data->reg_rs2;
            data->reg_rs2 = temp;
        }
        break;

        case I_MV: {
            // the I_BNEZ pseudo instruction is converted to the I_BNE instruction
            // mv rd, rs --> addi rd, rs, 0
            // mv a0, a5 --> addi a0, a5, 0
            // see: https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
            data->instruction = I_ADDI;
            data->instruction_type = IT_B;
            data->reg_rs2 = R_ZERO;
            data->imm = 0;
        }
        break;

        case I_NOP: {
            reset_asm_line(data);
            data->instruction = I_ADDI;
            data->instruction_type = IT_I;
            data->reg_rd = R_ZERO;
            data->reg_rs1 = R_ZERO;
            data->imm = 0;
        }
        break;

        case I_NOT: {
            // not rd, rs --> xori rd, rs, -1
            // see: https://stackoverflow.com/questions/65006052/how-do-i-write-not-operation-for-the-risc-v-assembly-language
            // see: https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
            data->instruction = I_XORI;
            data->instruction_type = IT_I;
            data->reg_rd = R_ZERO;
            data->reg_rs1 = R_ZERO;
            data->reg_rs2 = R_UNDEFINED_REGISTER;
            data->imm = -1;
        }
        break;

        case I_RET: {
            // pseudo instruction
            // ret --> jalr x0, x1, 0
            //
            // someone has to place the return address into x0 so ret will jump to it
            // see: https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
            data->instruction = I_JALR;
            data->instruction_type = IT_J;
            data->reg_rd = R_ZERO;
            data->reg_rs1 = R_RA;
            data->imm = 0;
        }
        break;
    }
}

int32_t retrieve_immediate_part(asm_line_t* asm_line) {

    int32_t imm = 0;

    if (asm_line->offset_0_used) {
        imm = asm_line->offset_0;
    } else if (asm_line->offset_1_used) {
        imm = asm_line->offset_1;
    } else if (asm_line->offset_2_used) {
        imm = asm_line->offset_2;
    } else if (asm_line->offset_0_expression != NULL) {
        imm = asm_line->offset_0_expression->int_val;
    } else if (asm_line->offset_1_expression != NULL) {
        imm = asm_line->offset_1_expression->int_val;
    } else if (asm_line->offset_2_expression != NULL) {
        imm = asm_line->offset_2_expression->int_val;
    } else {
        imm = asm_line->imm;
    }

    return imm;
}