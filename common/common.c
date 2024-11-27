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

//
// https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring
//

// trim from start (in place)
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
std::string trim_copy(std::string s) {
    trim(s);
    return s;
}

std::vector<std::string> split_string_by_delimiter(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split_string_by_delimiter(s, delim, std::back_inserter(elems));
    return elems;
}