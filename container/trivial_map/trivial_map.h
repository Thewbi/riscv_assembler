#ifndef TRIVIAL_MAP
#define TRIVIAL_MAP

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

typedef struct trivial_map_element {

    char key[100];
    int32_t value;
    int used;

} trivial_map_element_t;

void initialize_element(trivial_map_element_t* element);

void initialize_trivial_map(trivial_map_element_t* map, const int size);

int contains_key_trivial_map(const trivial_map_element_t* map, const int size, const char* key);

int insert_or_replace_trivial_map(trivial_map_element_t* map, const int size, const char* key, const int value);

// returns 0 if the key was not contained and no value has been retrieved
// returns 1 if a key was found and the value is returned in the value [out] parameter
//
// @param map       the map to search in
// @param size      the maximum amount of elements that may be stored in the map (not the actually stored elements)
// @param key       the key to retrieve the value for
// @param value     [out] returns the retrieved value (for the key) here
int retrieve_by_key_trivial_map(const trivial_map_element_t* map, const int size, const char* key, int* value);

void print_trivial_map(trivial_map_element_t* map, const int size);

#endif