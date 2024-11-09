#include "tuple_set.h"

void initialize_tuple_set_element(tuple_set_element_t* element) {
    memset(element->key, 0, 100);
    element->used = 0;
    element->value = 0;
}

void initialize_tuple_set(tuple_set_element_t* set, const int size) {
    for (int i = 0; i < size; i++) {
        initialize_tuple_set_element(set+i);
    }
}

int contains_key_tuple_set(const tuple_set_element_t* set, const int size, const char* key) {
    for (int i = 0; i < size; i++) {
        const tuple_set_element_t* element = set+i;
        if ((strncmp(element->key, key, 100) == 0) && (element->used == 1)) {
            return 1;
        }
    }
    return 0;
}

// if the { key, value } tuple is contained already, nothing happens
int insert_tuple_set(tuple_set_element_t* set,
    const int size, const char* key, const uint32_t value) {

    int first_free_index = -1;

    for (int i = 0; i < size; i++) {
        if (set[i].used) {
            // nothing
        } else {
            //printf("%d) empty\n", i);
            if (first_free_index < 0) {
                first_free_index = i;
                break;
            }
        }
    }

    if (first_free_index >= 0) {
        tuple_set_element_t* element = &set[first_free_index];
        strncpy(element->key, key, 100);
        element->value = value;
        element->used = 1;

        return 1;
    }

    return 0;
}

// returns 0 if there exists no tuple satisfying the condition ( tuple.key == key )
// returns 1 if a tuple was found. The tuple is returned in the value [out] parameter.
// If there is more than one tuple having the key, the first tuple found is returned.
//
// @param set       the set to search in
// @param size      the maximum amount of elements that may be stored in the map (not the actually stored elements)
// @param key       the key to retrieve the value for
// @param result    [out] returns the retrieved value (for the key) here
int retrieve_by_key_tuple_set(tuple_set_element_t* set,
    const int size, const char* key, tuple_set_element_t** result) {

    for (int i = 0; i < size; i++) {
        const tuple_set_element_t* element = set+i;
        if ((strncmp(element->key, key, 100) == 0) && (element->used == 1)) {
            *result = &set[i];
            return 1;
        }
    }
    return 0;
}

// returns 0 if there exists no tuple satisfying the condition ( tuple.key == key && tuple.value < value )
// returns 1 if a tuple was found. The tuple is returned in the value [out] parameter
//
// @param set       the set to search in
// @param size      the maximum amount of elements that may be stored in the map (not the actually stored elements)
// @param key       the key to retrieve the value for
// @param value     the value to retrieve the tuple for
// @param result    [out] returns the retrieved value (for the key and relative value) here
int retrieve_by_key_less_than_value_tuple_set(const tuple_set_element_t* set,
    const int size, const char* key, const uint32_t value, tuple_set_element_t* result) {

}

// returns 0 if there exists no tuple satisfying the condition ( tuple.key == key && tuple.value > value )
// returns 1 if a tuple was found. The tuple is returned in the value [out] parameter
//
// @param set       the set to search in
// @param size      the maximum amount of elements that may be stored in the map (not the actually stored elements)
// @param key       the key to retrieve the value for
// @param value     the value to retrieve the tuple for
// @param result     [out] returns the retrieved value (for the key and relative value) here
int retrieve_by_key_greater_than_value_tuple_set(const tuple_set_element_t* set,
    const int size, const char* key, const uint32_t value, tuple_set_element_t* result) {

}

void print_tuple_set(tuple_set_element_t* set, const int size);