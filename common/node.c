#include "node.h"

void reset_node(node_t* node) {

    node->left = NULL;
    node->right = NULL;

    node->int_val = 0;
    memset(node->string_val, 0, 100);
}