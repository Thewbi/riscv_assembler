#ifndef TOUPLE_SET_TEST
#define TOUPLE_SET_TEST

#include <container/tuple_set/tuple_set.h>

void initialize_tuple_set_element_test(void **state);

void tuple_set_initialize_test(void **state);

void insert_tuple_set_test(void **state);

void contains_key_tuple_set_not_contained_test(void **state);

void contains_key_tuple_set_contained_test(void **state);

void retrieve_by_key_tuple_set_test(void **state);

void retrieve_by_key_tuple_set_not_contained_test(void **state);

#endif