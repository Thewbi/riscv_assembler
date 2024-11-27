#ifndef COMMON
#define COMMON

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include <sstream>
#include <vector>
#include <iterator>

uint16_t sign_extend_uint16_t(uint16_t data);
uint32_t sign_extend_8_bit_to_uint32_t(const uint8_t data);
uint32_t sign_extend_12_bit_to_uint32_t(const uint16_t data);
int32_t sign_extend_12_bit_to_int32_t(const uint16_t data);
uint32_t sign_extend_20_bit_to_uint32_t(const uint32_t data);

// trim from start (in place)
void ltrim(std::string &s);

// trim from end (in place)
void rtrim(std::string &s);

// trim from both ends (in place)
void trim(std::string &s);

// trim from start (copying)
std::string ltrim_copy(std::string s);

// trim from end (copying)
std::string rtrim_copy(std::string s);

// trim from both ends (copying)
std::string trim_copy(std::string s);

//
// https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
//

template <typename Out>
void split_string_by_delimiter(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split_string_by_delimiter(const std::string &s, char delim);

#endif