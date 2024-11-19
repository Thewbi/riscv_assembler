#include <trivial_map/trivial_map.h>

void initialize_element(trivial_map_element_t* element) {
    memset(element->key, 0, 100);
    element->value = 0;
    element->used = 0;
}

void initialize_trivial_map(trivial_map_element_t* map, int size) {
    for (int i = 0; i < size; i++) {
        initialize_element(&map[i]);
    }
}

int contains_key_trivial_map(const trivial_map_element_t* map, int size, const char* key) {
    for (int i = 0; i < size; i++) {
        if ((map[i].used == 1) && (strncmp(map[i].key, key, 100) == 0)) {
            return 1;
        }
    }
    return 0;
}

int insert_or_replace_trivial_map(trivial_map_element_t* map, const int size, const char* key, const int value) {

    int first_free_index = -1;

    for (int i = 0; i < size; i++) {
        if (map[i].used) {
            //printf("%d) %s <-> %d \n", i, map[i].key, map[i].value);

            if (strncmp(map[i].key, key, 100) == 0) {
                map[i].value = value;

                return 1;
            }
        } else {
            //printf("%d) empty\n", i);
            if (first_free_index < 0) {
                first_free_index = i;
            }
        }
    }

    if (first_free_index >= 0) {
        strncpy(map[first_free_index].key, key, 100);
        map[first_free_index].value = value;
        map[first_free_index].used = 1;

        return 1;
    }

    return 0;
}

int retrieve_by_key_trivial_map(const trivial_map_element_t* map, const int size, const char* key, int* value) {
    for (int i = 0; i < size; i++) {
        if (map[i].used) {
            //printf("%d) %s <-> %d \n", i, map[i].key, map[i].value);

            if (strncmp(map[i].key, key, 100) == 0) {
                *value = map[i].value;

                return 1;
            }
        }
    }
    return 0;
}

void print_trivial_map(trivial_map_element_t* map, int size) {
    for (int i = 0; i < size; i++) {
        if (map[i].used) {
            printf("%d) %s <-> %08" PRIx64 "\n", i, map[i].key, map[i].value);
        } else {
            printf("%d) empty\n", i);
        }
    }
}