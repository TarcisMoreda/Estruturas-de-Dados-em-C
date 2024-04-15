#include <stdlib.h>
#include <stdio.h>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree_t BinaryTree;

BinaryTree *binary_tree_create(int value);
int binary_tree_insert(BinaryTree *tree, int value);
int binary_tree_remove(BinaryTree *tree, int value);
void binary_tree_destroy(BinaryTree *tree);
int binary_tree_print_in_order(BinaryTree *tree);
int binary_tree_print_pre_order(BinaryTree *tree);
int binary_tree_print_post_order(BinaryTree *tree);

#endif // BINARY_TREE_H