#include "common.h"

uint16_t sign_extend_uint16_t(uint16_t data) {
    uint16_t sign = data & 0b100000000000;
    if (sign) {
        return 0b1111000000000000 | data;
    }
    return data;
}

uint32_t sign_extend_8_bit_to_uint32_t(const uint8_t data) {
    uint32_t most_significant_bit = data & 0b10000000;
    if (most_significant_bit) {
        return 0xFFFFFF00 | data;
    }
    return data;
}

uint32_t sign_extend_12_bit_to_uint32_t(const uint16_t data) {
    uint32_t most_significant_bit = data & 0b100000000000;
    if (most_significant_bit) {
        return 0xFFFFF000 | data;
    }
    return data;
}

int32_t sign_extend_12_bit_to_int32_t(const uint16_t data) {
    uint32_t most_significant_bit = data & 0b100000000000;
    if (most_significant_bit) {
        return 0xFFFFF000 | data;
    }
    return data;
}

uint32_t sign_extend_20_bit_to_uint32_t(const uint32_t data) {
    uint32_t most_significant_bit = data & 0b10000000000000000000;
    if (most_significant_bit) {
        return 0xFFF00000 | data;
    }
    return data;
}