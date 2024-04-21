#include <stdlib.h>
#include <stdio.h>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree_t BinaryTree;

BinaryTree *binary_tree_create(const int value);
char binary_tree_insert(BinaryTree *tree, const int value);
char binary_tree_remove(BinaryTree *tree, const int value);
void binary_tree_destroy(BinaryTree *tree);
void binary_tree_print_in_order(BinaryTree *tree);
void binary_tree_print_pre_order(BinaryTree *tree);
void binary_tree_print_post_order(BinaryTree *tree);
char binary_tree_balance(BinaryTree *tree);

#endif // BINARY_TREE_H