#include "asm_line.h"

void reset_asm_line(asm_line_t *data) {

    //printf("reset\n");

    //
    // general
    //

    data->used = 0;
    data->line_nr = 0;
    data->size_in_bytes = 0;

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
    target->size_in_bytes = source->size_in_bytes;

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
    //target->offset_identifier_0 = source->offset_identifier_0; // TODO: deep copy?
    memcpy(target->offset_identifier_0, source->offset_identifier_0, 100);
    target->offset_0_used = source->offset_0_used;
    target->offset_0_expression = source->offset_0_expression; // TODO: deep copy?

    target->offset_1 = source->offset_1;
    //target->offset_identifier_1 = source->offset_identifier_1; // TODO: deep copy?
    memcpy(target->offset_identifier_1, source->offset_identifier_1, 100);
    target->offset_1_used = source->offset_1_used;
    target->offset_1_expression = source->offset_1_expression; // TODO: deep copy?

    target->offset_2 = source->offset_2;
    //target->offset_identifier_2 = source->offset_identifier_2; // TODO: deep copy?
    memcpy(target->offset_identifier_2, source->offset_identifier_2, 100);
    target->offset_2_used = source->offset_2_used;
    target->offset_2_expression = source->offset_2_expression; // TODO: deep copy?
}

void print_asm_line(const asm_line_t *data) {

    //printf("print_asm_line\n");
    //printf("print_asm_line label: %s \n", data->label);

    // if (strlen(data->label) != 0) {

    //     printf("[(%d) Label: %s]\n", data->line_nr, data->label);

    // } else

    if (data->asm_instruction != AI_UNDEFINED) {

        char buffer_3[100];

        memset(buffer_3, 0, 100);

        //printf("print_expression ...\n");
        print_expression(data->asm_instruction_expr, buffer_3);
        //printf("print_expression done.\n");

        printf("[(%d) AssemblerInstr: Label:%s Instr:%s Symbol:%s Val: %s]\n",
            data->line_nr,
            data->label,
            assembler_instruction_to_string(data->asm_instruction),
            data->asm_instruction_symbol, buffer_3);

    } else {

        //printf("asm_line with parameters\n");

        char buffer_0[100];
        char buffer_1[100];
        char buffer_2[100];

        memset(buffer_0, 0, 100);
        memset(buffer_1, 0, 100);
        memset(buffer_2, 0, 100);

        print_expression(data->offset_0_expression, buffer_0);
        print_expression(data->offset_1_expression, buffer_1);
        print_expression(data->offset_2_expression, buffer_2);

        printf("[(%d) Label: %s, Instr: %s Size: %d Imm: %d Used: %d \n \
    0:{offset_0_used:%d offset:%d offset_ident:%s register:%s offset_0_expr:%s}\n \
    1:{offset_1_used:%d offset:%d offset_ident:%s register:%s offset_1_expr:%s}\n \
    2:{offset_2_used:%d offset:%d offset_ident:%s register:%s offset_2_expr:%s}\n \
]\n",
            data->line_nr,
            data->label,
            instruction_to_string(data->instruction),
            data->size_in_bytes,
            data->imm,
            data->used,
            data->offset_0_used, data->offset_0, data->offset_identifier_0, register_to_string(data->reg_rd), buffer_0,
            data->offset_1_used, data->offset_1, data->offset_identifier_1, register_to_string(data->reg_rs1), buffer_1,
            data->offset_2_used, data->offset_2, data->offset_identifier_2, register_to_string(data->reg_rs2), buffer_2);

    }

}

void serialize_asm_line(const asm_line_t *data) {

    // if (strlen(data->label) != 0) {

    //     //printf("[(%d) Label: %s]\n", data->line_nr, data->label);

    // } else

    if (data->asm_instruction != AI_UNDEFINED) {

        // char buffer_3[100];

        // memset(buffer_3, 0, 100);

        // //printf("print_expression ...\n");
        // print_expression(data->asm_instruction_expr, buffer_3);
        // //printf("print_expression done.\n");

        // printf("[(%d) AssemblerInstr: Instr:%s Symbol:%s Val: %s]\n",
        //     data->line_nr,
        //     assembler_instruction_to_string(data->asm_instruction),
        //     data->asm_instruction_symbol, buffer_3);

    } else {

        //printf("asm_line with parameters\n");

//         char buffer_0[100];
//         char buffer_1[100];
//         char buffer_2[100];

//         memset(buffer_0, 0, 100);
//         memset(buffer_1, 0, 100);
//         memset(buffer_2, 0, 100);

//         print_expression(data->offset_0_expression, buffer_0);
//         print_expression(data->offset_1_expression, buffer_1);
//         print_expression(data->offset_2_expression, buffer_2);

//         printf("[(%d) Instr: %s Size: %d\n\
//     0:{offset_used:%d offset:%d offset_ident:%s register:%s offset_expr:%s}\n\
//     1:{offset_used:%d offset:%d offset_ident:%s register:%s offset_expr:%s}\n\
//     2:{offset_used:%d offset:%d offset_ident:%s register:%s offset_expr:%s}\n\
// ]\n",
//             data->line_nr,
//             instruction_to_string(data->instruction),
//             data->size_in_bytes,
//             data->offset_0_used, data->offset_0, data->offset_identifier_0, register_to_string(data->reg_rd), buffer_0,
//             data->offset_1_used, data->offset_1, data->offset_identifier_1, register_to_string(data->reg_rs1), buffer_1,
//             data->offset_2_used, data->offset_2, data->offset_identifier_2, register_to_string(data->reg_rs2), buffer_2);

        printf("%s ", instruction_to_string(data->instruction));

        switch (data->instruction) {

            // I-Type
            case I_ADDI:
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
                break;

            // R-Type
            case I_ADD:
            case I_MUL:
                printf("%s, ", register_to_string(data->reg_rd));
                printf("%s, ", register_to_string(data->reg_rs1));
                printf("%s ", register_to_string(data->reg_rs2));
                break;

            // S-Type
            case  I_SW: // store word
                printf("%s, ", register_to_string(data->reg_rs1));
                // printf("%s(", register_to_string(data->reg_rs2));
                // printf("0x%08" PRIx32 "", data->imm);
                // printf(")");
                printf("0x%08" PRIx32 "", data->imm);
                printf("(%s)", register_to_string(data->reg_rs2));
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

            // // J-Type
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

    //printf("insert_register()\n");

    if (data->instruction_type == IT_B || data->instruction_type == IT_S) {

        //printf("insert_register() IT_B IT_S\n");

        if (R_UNDEFINED_REGISTER == data->reg_rs1) {
            data->reg_rs1 = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs2) {
            data->reg_rs2 = reg;
            return;
        }

    } else {

        //printf("insert_register()\n");

        if (R_UNDEFINED_REGISTER == data->reg_rd) {
            //printf("insert_register() insert into rd \n");
            data->reg_rd = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs1) {
            //printf("insert_register() insert into rs1 \n");
            data->reg_rs1 = reg;
            return;
        }
        if (R_UNDEFINED_REGISTER == data->reg_rs2) {
            //printf("insert_register() insert into rs2 \n");
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

const char* instruction_to_string(enum instruction data) {

    if (data == I_UNDEFINED_INSTRUCTION) {
        return "I_UNDEFINED_INSTRUCTION";
    }

    switch (data) {

        case I_ADD: return "ADD";
        case I_ADDI: return "ADDI";
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
        case I_JAL: return "JAL";
        case I_JALR: return "JALR";

        case I_LB: return "LB";
        case I_LH: return "LH";
        case I_LBU: return "LBU";
        case I_LHU: return "LHU";
        case I_LI: return "LI"; // pseudo instruction
        case I_LUI: return "LUI";
        case I_LW: return "LW";

        case I_MUL: return "MUL";
        case I_MV: return "MV"; // pseudo instruction

        case I_ORI: return "ORI";

        case I_RET: return "RET";

        case I_SLLI: return "SLLI";
        case I_SRLI: return "SRLI";
        case I_SLTIU: return "SLTIU";
        case I_SW: return "SW";

        case I_XORI: return "XORI";

        default: {
            return "UNKNOWN";
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

        default: return "UNKNOWN ASSEMBLER INSTRUCTION!";
    }
}

const char* register_to_string(enum register_ data) {

    int outputABIName = 0;
    if (outputABIName) {

        switch(data) {
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

void set_instruction(asm_line_t *data, const enum instruction instr, const enum instruction_type type) {

    //printf("set_instruction()\n");

    data->instruction = instr;
    data->instruction_type = type;

    data->size_in_bytes = 4;
    switch (data->instruction) {

        case I_CALL:
            data->size_in_bytes = 8;
            break;

        // pseudo instruction -> is replaced with JAL
        case I_J:
            data->size_in_bytes = 4;
            break;

        case I_LI:
            data->size_in_bytes = 8;
            break;

        case I_MV:
            data->size_in_bytes = 4;
            break;
    }

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
            beq.reg_rs1 = data->reg_rd;
            beq.reg_rs2 = R_ZERO;
            beq.imm = imm_int_val;

            reset_asm_line(data);
            copy_asm_line(data, &beq);

        }
        break;

        case I_CALL: {

            int line_nr = data->line_nr;

            // if (data->offset_0_expression == NULL) {
            //     printf("error\n");
            // }

            //uint32_t imm_int_val = data->offset_0_expression->int_val;
            uint32_t imm_int_val = 0;
            if (data->offset_0_used) {
                imm_int_val = data->offset_0;
            }

            uint32_t data_0 = (imm_int_val & 0xFFFFF000) >> 12;
            uint32_t data_1 = (imm_int_val & 0xFFF);

            // TODO: search for a register that is really free
            enum register_ free_temp_register = R_T1; // x6

            //
            // auipc
            //

            //uint8_t opcode = 0b0010111;
            //uint8_t rd = encode_register(free_temp_register);
            uint32_t imm = data_0;

            asm_line_t auipc;
            reset_asm_line(&auipc);
            auipc.used = 1;
            auipc.line_nr = line_nr;
            auipc.instruction = I_AUIPC;
            auipc.instruction_type = IT_U;
            auipc.reg_rd = free_temp_register;
            auipc.imm = imm;

            //
            // jalr
            //

            //uint8_t funct3 = 0b000;
            //opcode = 0b1100111;

            //rd = encode_register(R_ZERO);
            uint8_t rs1 = encode_register(free_temp_register);
            imm = data_1;

            asm_line_t jalr;
            reset_asm_line(&jalr);
            jalr.used = 1;
            jalr.line_nr = line_nr + 1;
            jalr.instruction = I_JALR;
            jalr.instruction_type = IT_J;
            jalr.reg_rd = R_ZERO;
            jalr.reg_rs1 = free_temp_register;
            jalr.imm = imm;

            reset_asm_line(data);

            for (int i = size-1; i > index; i--) {
                copy_asm_line(&asm_line_array[i+1], &asm_line_array[i]);
                asm_line_array[i+1].line_nr++;
            }

            copy_asm_line(data, &auipc);
            copy_asm_line(&asm_line_array[index+1], &jalr);
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
            if (data->offset_1_expression->int_val > 0xFFF) {
                printf("boink");

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
                auipc.reg_rd = data->reg_rd;
                auipc.imm = (data->offset_1_expression->int_val >> 12);

                //reset_asm_line(data);

                // modify rs1 register
                data->reg_rs1 = data->reg_rd;

                for (int i = (size-1); i >= index; i--) {

                    copy_asm_line(&asm_line_array[i + 1], &asm_line_array[i]);
                    asm_line_array[i + 1].line_nr++;

                    // printf("%d: ", i);
                    // print_asm_line(&asm_line_array[i]);
                    // printf(" %d: ", i+1);
                    // print_asm_line(&asm_line_array[i + i]);
                }

                // for (int i = 0; i < 100; i++) {
                //     //printf("line %d\n", i);
                //     if (asm_line_array[i].used != 0) {
                //         print_asm_line(&asm_line_array[i]);
                //     }
                // }

                asm_line_t* next_data = &asm_line_array[index + 1];

                //data->offset_1_expression->int_val = data->offset_1_expression->int_val & 0xFFF;
                next_data->imm = next_data->offset_1_expression->int_val & 0xFFF;

                // adjust the immediate value of the lb instruction
                next_data->offset_1_expression->int_val = 0x00;


                reset_asm_line(data);
                copy_asm_line(data, &auipc);
                //copy_asm_line(&asm_line_array[index+1], &jalr);
            }
        }
        break;

        case I_LI: {

            int line_nr = data->line_nr;

            // take the 32 bit value (data_0)
            uint32_t data_0 = 0;

            if (data->offset_0_used) {
                data_0 = data->offset_1;
            } else {
                data_0 = data->offset_1_expression->int_val;
            }

            // split it into a 20 bit (data_1) and a twelve bit part (is ignored)
            uint32_t data_1 = ((data_0 & 0b11111111111111111111000000000000) >> 12);

            // the 20 bit part is incremented by 1, (then shifted left by 12 bits to get (data_2))
            //data_1 = data_1 + 1;

            //
            // lui
            //

            //uint8_t opcode = 0b0110111;
            uint8_t rd = encode_register(data->reg_rd);
            uint32_t imm = data_1;

            asm_line_t lui;
            reset_asm_line(&lui);
            lui.used = 1;
            lui.line_nr = line_nr;
            lui.instruction = I_LUI;
            lui.instruction_type = IT_U;
            lui.reg_rd = data->reg_rd;
            lui.imm = imm;

            //
            // addi
            //

            uint32_t data_2 = data_1 << 12;
            uint32_t data_3 = (data_0 - data_2) & 0xFFF;
            //printf("data_3: %08" PRIx32 "\n", data_3);

            //uint8_t funct3 = 0b000;
            //opcode = 0b0010011;

            rd = encode_register(data->reg_rd);
            uint8_t rs1 = encode_register(data->reg_rd);
            imm = data_3;

            asm_line_t addi;
            reset_asm_line(&addi);
            addi.used = 1;
            addi.line_nr = line_nr + 1;
            addi.instruction = I_ADDI;
            addi.instruction_type = IT_I;
            addi.reg_rd = data->reg_rd;
            addi.reg_rs1 = data->reg_rd;
            addi.imm = imm;

            // //asm_line_array[index] = lui;

            // for (int i = size-1; i--; i > index) {
            //     copy_asm_line(&asm_line_array[i+1], &asm_line_array[i]);
            // }
            // reset_asm_line(&asm_line_array[index]);
            // reset_asm_line(&asm_line_array[index+1]);
            // //asm_line_array[index + 1] = addi;
            // copy_asm_line(&asm_line_array[index+1], &addi);

            //printf("index: %d\n", index);

            reset_asm_line(data);

            for (int i = size-1; i > index; i--) {
                //printf("index: %d\n", (i > index));
                //printf("copy %d <- %d\n", i+1, i);
                copy_asm_line(&asm_line_array[i + 1], &asm_line_array[i]);
                asm_line_array[i + 1].line_nr++;
            }

            copy_asm_line(data, &lui);
            copy_asm_line(&asm_line_array[index + 1], &addi);
        }
        break;

        case I_BNEZ: {
            // the I_BNEZ pseudo instruction is converted to the I_BNE instruction
            // bnez rs, offset => bne rs, x0, offset
            // see: https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
            data->instruction = I_BNE;
            data->instruction_type = IT_I;
            // data->reg_rd = data->reg_rd;
            // data->reg_rs1 = data->reg_rd;
            data->reg_rs1 = data->reg_rd;
            data->reg_rs2 = data->reg_rd;
            data->imm = 0;
        }
        break;

        case I_BGT: {
            // the I_BNEZ pseudo instruction is converted to the I_BNE instruction
            // bnez rs, offset => bne rs, x0, offset
            // see: https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
            data->instruction = I_BLT;
            data->instruction_type = IT_B;
            // data->reg_rd = data->reg_rd;
            // data->reg_rs1 = data->reg_rd;
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
            data->reg_rs1 = R_ZERO;
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