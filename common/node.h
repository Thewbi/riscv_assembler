#ifndef NODE
#define NODE

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

typedef struct node {
    struct node* left;
    struct node* right;

    char string_val[100];
    int int_val;
} node_t;

void reset_node(node_t* node);

#endif