#ifndef ASSEMBLER
#define ASSEMBLER

#include <map>

int assemble(const char* filename, uint32_t* machine_code, std::map<uint32_t, uint32_t*>* segments);

#endif