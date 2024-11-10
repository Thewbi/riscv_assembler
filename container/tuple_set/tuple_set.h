#ifndef TUPLE_SET
#define TUPLE_SET

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

// this tuple set has been create since in assembly it is possible to
// have two labels of the exact same name which then only differ in the
// address they represent.
//
// In assembly the labelname can then be used by postfixing it with either
// 'f' for forward variant of the label or 'b' for backward variant of the
// label.
//
// Forward and backward means that relative to the address of the
// assembler instruction that references the label, both labels can be
// identified as being the forward or the backward label.
//
// When the current instruction references the label with the 'f' postfix,
// the label is replace with the address of the forward label, otherwise
// the backward label is used.
//
// To identify the backward label, call retrieve_by_key_less_than_value_tuple_set()
// To identify the forward label, call retrieve_by_key_greater_than_value_tuple_set()
//
// If you just want to identify the label by name, call retrieve_by_key_tuple_set()

typedef struct tuple_set_element {

    char key[100];
    uint32_t value;

    // is this entry used or currently only used to provide free memory
    int used;

} tuple_set_element_t;

void initialize_tuple_set_element(tuple_set_element_t* element);

void initialize_tuple_set(tuple_set_element_t* set, const int size);

int contains_key_tuple_set(const tuple_set_element_t* set, const int size, const char* key);

// if the { key, value } tuple is contained already, nothing happens
int insert_tuple_set(tuple_set_element_t* set, const int size, const char* key, const uint32_t value);

// returns 0 if there exists no tuple satisfying the condition ( tuple.key == key )
// returns 1 if a tuple was found. The tuple is returned in the value [out] parameter.
// If there is more than one tuple having the key, the first tuple found is returned.
//
// @param set       the set to search in
// @param size      the maximum amount of elements that may be stored in the map (not the actually stored elements)
// @param key       the key to retrieve the value for
// @param result    [out] returns the retrieved value (for the key) here
int retrieve_by_key_tuple_set(tuple_set_element_t* set, const int size, const char* key, tuple_set_element_t** result);

// returns 0 if there exists no tuple satisfying the condition ( tuple.key == key && tuple.value < value )
// returns 1 if a tuple was found. The tuple is returned in the value [out] parameter
//
// @param set       the set to search in
// @param size      the maximum amount of elements that may be stored in the map (not the actually stored elements)
// @param key       the key to retrieve the value for
// @param value     the value to retrieve the tuple for
// @param result    [out] returns the retrieved value (for the key and relative value) here
int retrieve_by_key_less_than_value_tuple_set(tuple_set_element_t* set,
    const int size, const char* key, const uint32_t value, tuple_set_element_t** result);

// returns 0 if there exists no tuple satisfying the condition ( tuple.key == key && tuple.value > value )
// returns 1 if a tuple was found. The tuple is returned in the value [out] parameter
//
// @param set       the set to search in
// @param size      the maximum amount of elements that may be stored in the map (not the actually stored elements)
// @param key       the key to retrieve the value for
// @param value     the value to retrieve the tuple for
// @param result     [out] returns the retrieved value (for the key and relative value) here
int retrieve_by_key_greater_than_value_tuple_set(tuple_set_element_t* set,
    const int size, const char* key, const uint32_t value, tuple_set_element_t** result);

void print_tuple_set(tuple_set_element_t* set, const int size);

#endif