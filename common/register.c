#include "register.h"

uint8_t encode_register(enum register_ data) {

    switch (data) {

        case R_ZERO: // 0, Hard-wired zero
            return 0b00000;

        case R_RA: // 1, Return address
            return 0b00001;

        case R_SP: // 2, Stack pointer
            return 0b00010;

        case R_GP: // 3, Global pointer
            return 0b00011;

        case R_TP: // 4, Thread pointer
            return 0b00100;

        // ABI Name: t0, Register: x5 - encoded: 0101 (= 5 decimal)
        case R_T0: // 5, Temporary/alternate link register
            return 0b00101;

        case R_T1: // 6, Temporary
            return 0b00110;

        case R_T2: // 7, Temporary
            return 0b00111;

        case R_S0: // 8, Saved register/frame pointer
            return 0b01000;

        case R_S1: // 9, Saved register
            return 0b01001;

        // ABI Name: a0, Register: x10 - encoded: 1010 (= 10 decimal)
        case R_A0: // 10, Function arguments/return values
             return 0b01010;

        case R_A1: // 11, Function arguments/return values
            return 0b01011;

        case R_A2: // 12, Function arguments
            return 0b01100;

        case R_A3: // 13, Function arguments
            return 0b01101;

        case R_A4: // 14, Function arguments
            return 0b01110;

        case R_A5: // 15, Function arguments
            return 0b01111;

        case R_A6: // 16, Function arguments
            return 0b10000;

        case R_A7: // 17, Function arguments
            return 0b10001;

        case R_S2: // 18, Saved registers
            return 0b10010;

        case R_S3: // 19, Saved registers
            return 0b10011;

        case R_S4: // 20, Saved registers
            return 0b10100;

        case R_S5: // 21, Saved registers
            return 0b10101;

        case R_S6: // 22, Saved registers
            return 0b10110;

        case R_S7: // 23, Saved registers
            return 0b10111;

        case R_S8: // 24, Saved registers
            return 0b11000;

        case R_S9: // 25, Saved registers
            return 0b11001;

        case R_S10: // 26, Saved registers
            return 0b11010;

        case R_S11: // 27, Saved registers
            return 0b11011;

        case R_T3: // 28, Temporary
            return 0b11100;

        case R_T4: // 29, Temporary
            return 0b11101;

        case R_T5: // 30, Temporary
            return 0b11110;

        case R_T6: // 31, Temporary
            return 0b11111;

        default:
            printf("unknown register %d\n", data);
            return 0;
    }
}