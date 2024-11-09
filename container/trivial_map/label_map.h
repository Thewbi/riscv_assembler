#ifndef LABEL_MAP
#define LABEL_MAP

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

typedef struct label_map_element {

    // uniquely identified by key (= labelname) and line number
    char key[100];
    int line_nr;

    int32_t value;

    int used;

} label_map_element_t;

void initialize_element(label_map_element* element);

void initialize_label_map(label_map_element* map, const int size);

int contains_key_label_map(const label_map_element* map, const int size, const char* key);

int insert_or_replace_label_map(label_map_element* map, const int size, const char* key, const int const int value);

// returns 0 if the key was not contained and no value has been retrieved
// returns 1 if a key was found and the value is returned in the value [out] parameter
//
// @param map       the map to search in
// @param size      the maximum amount of elements that may be stored in the map (not the actually stored elements)
// @param key       the key to retrieve the value for
// @param value     [out] returns the retrieved value (for the key) here
int retrieve_by_key_label_map(const label_map_element* map, const int size, const char* key, int* value);

void print_label_map(label_map_element* map, const int size);

#endif