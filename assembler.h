#ifndef ASSEMBLER
#define ASSEMBLER

#include <map>

int assemble(const char* filename, uint32_t* machine_code, std::map<uint32_t, uint32_t*>* segments);

uint32_t determine_instruction_size(asm_line_t* data, int label_exists_in_file);

#endif