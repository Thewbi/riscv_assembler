#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <setjmp.h>
#include <cmocka.h>

#include "tuple_set_test.h"

void initialize_tuple_set_element_test(void **state) {

    // Arrange

    tuple_set_element_t element;

    // Act

    initialize_tuple_set_element(&element);

    // Assert

    assert_int_equal(0, element.key[0]);
    assert_int_equal(0, element.value);
    assert_int_equal(0, element.used);

}


void tuple_set_initialize_test(void **state) {

    // Arrange

    tuple_set_element_t tuple_set[20];

    // Act

    initialize_tuple_set(tuple_set, 20);

    // Assert

    for (int i = 0; i < 20; i++) {
        tuple_set_element_t* element = &tuple_set[i];
        assert_int_equal(0, element->key[0]);
        assert_int_equal(0, element->value);
        assert_int_equal(0, element->used);
    }

}

void insert_tuple_set_test(void **state) {

    // Arrange

    tuple_set_element_t tuple_set[20];
    initialize_tuple_set(tuple_set, 20);

    // Act

    insert_tuple_set(tuple_set, 20, "key_1", 1);
    insert_tuple_set(tuple_set, 20, "key_1", 2);
    insert_tuple_set(tuple_set, 20, "key_2", 1);
    insert_tuple_set(tuple_set, 20, "key_2", 2);

    // Assert

    int found = 0;
    for (int i = 0; i < 20; i++) {
        tuple_set_element_t* element = &tuple_set[i];
        if ((strncmp(element->key, "key_1", 100) == 0) && (element->value == 1) && (element->used == 1)) {
            found = 1;
            break;
        }
    }
    assert_int_equal(1, found);

    found = 0;
    for (int i = 0; i < 20; i++) {
        tuple_set_element_t* element = &tuple_set[i];
        if ((strncmp(element->key, "key_1", 100) == 0) && (element->value == 2) && (element->used == 1)) {
            found = 1;
            break;
        }
    }
    assert_int_equal(1, found);
}

void contains_key_tuple_set_not_contained_test(void **state) {

    // Arrange

    tuple_set_element_t tuple_set[20];
    initialize_tuple_set(tuple_set, 20);

    // Act

    int result = contains_key_tuple_set(tuple_set, 20, "key_1");

    // Assert

    assert_int_equal(0, result);

}

void contains_key_tuple_set_contained_test(void **state) {

    // Arrange

    tuple_set_element_t tuple_set[20];
    initialize_tuple_set(tuple_set, 20);

    strncpy(tuple_set[0].key, "key_1", 100);
    tuple_set[0].value = 1;
    tuple_set[0].used = 1;

    // Act

    int result = contains_key_tuple_set(tuple_set, 20, "key_1");

    // Assert

    assert_int_equal(1, result);

}

void retrieve_by_key_tuple_set_test(void **state) {

    // Arrange

    tuple_set_element_t tuple_set[20];
    initialize_tuple_set(tuple_set, 20);

    strncpy(tuple_set[0].key, "key_1", 100);
    tuple_set[0].value = 1;
    tuple_set[0].used = 1;

    // Act

    tuple_set_element_t* result_element;
    int result = retrieve_by_key_tuple_set(tuple_set, 20, "key_1", &result_element);

    // Assert

    // found a record
    assert_int_equal(1, result);

    // key matches, value matches, record is used
    assert_int_equal(0, strncmp(result_element->key, "key_1", 100));
    assert_int_equal(1, result_element->value);
    assert_int_equal(1, result_element->used);

}

void retrieve_by_key_tuple_set_not_contained_test(void **state) {

    // Arrange

    tuple_set_element_t tuple_set[20];
    initialize_tuple_set(tuple_set, 20);

    strncpy(tuple_set[0].key, "key_1", 100);
    tuple_set[0].value = 1;
    tuple_set[0].used = 1;

    // Act

    tuple_set_element_t* result_element;
    int result = retrieve_by_key_tuple_set(tuple_set, 20, "key_another_key", &result_element);

    // Assert

    // found n0 record
    assert_int_equal(0, result);

}