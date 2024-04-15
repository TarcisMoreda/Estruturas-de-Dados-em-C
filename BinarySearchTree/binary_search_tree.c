#include "binary_search_tree.h"

struct binary_tree_t
{
    int value;
    struct binary_tree_t *left;
    struct binary_tree_t *right;
};

BinaryTree *binary_tree_create(int value)
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));

    if (!tree)
        return NULL;

    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

int binary_tree_insert(BinaryTree *tree, int value)
{
    if (!tree)
        return 1;

    BinaryTree *new = (BinaryTree *)malloc(sizeof(BinaryTree));
    new->value = value;
    new->left = NULL;
    new->right = NULL;

    while (1)
    {
        if (value < tree->value)
            if (tree->left)
                tree = tree->left;
            else
            {
                tree->left = new;
                break;
            }
        else if (value > tree->value)
            if (tree->right)
                tree = tree->right;
            else
            {
                tree->right = new;
                break;
            }
        else
        {
            free(new);
            return 1;
        }
    }

    return 0;
}

int binary_tree_remove(BinaryTree *tree, int value)
{
    if (!tree)
        return 1;

    BinaryTree *root = tree;
    BinaryTree *aux = tree;

    while (tree->value != value)
    {
        aux = tree;

        if (value < tree->value)
        {
            if (!tree->left)
                return 1;
            tree = tree->left;
        }
        else if (value > tree->value)
        {
            if (!tree->right)
                return 1;
            tree = tree->right;
        }
    }

    if (!tree->left && !tree->right)
    {
        if (aux->left == tree)
            aux->left = NULL;
        else if (aux->right == tree)
            aux->right = NULL;
        else
            return 1;

        free(tree);

        return 0;
    }
    else if (tree->left && tree->right)
    {
        BinaryTree *prev_aux = aux;

        aux = tree->right;

        while (aux->left != NULL)
        {
            prev_aux = aux;
            aux = aux->left;
        }

        prev_aux->left = NULL;
        tree->value = aux->value;
        free(aux);

        return 0;
    }

    BinaryTree *solo = tree->left ? tree->left : tree->right;

    if (tree != root)
    {
        if (aux->left == tree)
            aux->left = solo;
        else
            aux->right = solo;
    }
    else
        root = solo;

    free(tree);

    return 0;
}

void binary_tree_destroy(BinaryTree *tree)
{
    if (tree == NULL)
        return;

    if (tree->left)
        binary_tree_destroy(tree->left);
    else if (tree->right)
        binary_tree_destroy(tree->right);

    free(tree);
}

int binary_tree_print_in_order(BinaryTree *tree)
{
    if (!tree)
        return 1;

    if (tree->left)
        binary_tree_print_in_order(tree->left);

    printf("%d ", tree->value);

    if (tree->right)
        binary_tree_print_in_order(tree->right);

    return 0;
}

int binary_tree_print_pre_order(BinaryTree *tree)
{
    if (!tree)
        return 1;

    printf("%d ", tree->value);

    if (tree->left)
        binary_tree_print_pre_order(tree->left);
    if (tree->right)
        binary_tree_print_pre_order(tree->right);

    return 0;
}

int binary_tree_print_post_order(BinaryTree *tree)
{
    if (!tree)
        return 1;

    if (tree->left)
        binary_tree_print_post_order(tree->left);
    if (tree->right)
        binary_tree_print_post_order(tree->right);

    printf("%d ", tree->value);

    return 0;
}