#include "binary_tree.h"

struct binary_tree_t
{
    int value;
    unsigned int height;
    struct binary_tree_t *left;
    struct binary_tree_t *right;
};

BinaryTree *binary_tree_create(const int value)
{
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));

    if (!tree)
        return NULL;

    tree->value = value;
    tree->height = 0;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

char binary_tree_insert(BinaryTree *tree, const int value)
{
    if (!tree)
        return 1;

    BinaryTree *new = (BinaryTree *)malloc(sizeof(BinaryTree));
    new->value = value;
    new->height = 0;
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

char binary_tree_remove(BinaryTree *tree, const int value)
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

void binary_tree_print_in_order(BinaryTree *tree)
{
    if (!tree)
        return;

    if (tree->left)
        binary_tree_print_in_order(tree->left);

    printf("%d ", tree->value);

    if (tree->right)
        binary_tree_print_in_order(tree->right);

    return;
}

void binary_tree_print_pre_order(BinaryTree *tree)
{
    if (!tree)
        return;

    printf("%d ", tree->value);

    if (tree->left)
        binary_tree_print_pre_order(tree->left);
    if (tree->right)
        binary_tree_print_pre_order(tree->right);

    return;
}

void binary_tree_print_post_order(BinaryTree *tree)
{
    if (!tree)
        return;

    if (tree->left)
        binary_tree_print_post_order(tree->left);
    if (tree->right)
        binary_tree_print_post_order(tree->right);

    printf("%d ", tree->value);

    return;
}

char binary_tree_balance(BinaryTree *tree)
{
    if (!tree)
        return 1;

    binary_tree_update_heights(tree);

    const unsigned int left_h = tree->left->height;
    const unsigned int right_h = tree->right->height;

    if (left_h > right_h + 1)
    {
        const unsigned int left_left_h = tree->left->left->height;
        const unsigned int left_right_h = tree->left->right->height;

        if (left_left_h >= left_right_h)
        {
            binary_tree_rotate_right(tree);
            return 0;
        }
        else
        {
            binary_tree_left_right(tree);
            return 0;
        }
    }
    if (right_h > left_h + 1)
    {
        const unsigned int right_right_h = tree->right->right->height;
        const unsigned int right_left_h = tree->right->left->height;

        if (right_right_h >= right_left_h)
        {
            binary_tree_rotate_left(tree);
            return 0;
        }
        else
        {
            binary_tree_right_left(tree);
            return 0;
        }
    }

    return 0;
}

void binary_tree_rotate_left(BinaryTree *tree)
{
    BinaryTree *new_root = tree->right;
    tree->right = new_root->left;
    new_root->left = tree;
    tree = new_root;
}

void binary_tree_rotate_right(BinaryTree *tree)
{
    BinaryTree *new_root = tree->left;
    tree->left = new_root->right;
    new_root->right = tree;
    tree = new_root;
}

void binary_tree_left_right(BinaryTree *tree)
{
    binary_tree_rotate_left(tree->left);
    binary_tree_rotate_right(tree);
}

void binary_tree_right_left(BinaryTree *tree)
{
    binary_tree_rotate_right(tree->right);
    binary_tree_rotate_left(tree);
}

void binary_tree_update_heights(BinaryTree *tree)
{
    if (!tree)
        return;
    if (!tree->left && !tree->right)
    {
        tree->height = 1;
        return;
    }

    unsigned int left = 0;
    unsigned int right = 0;

    if (tree->left)
    {
        binary_tree_update_heights(tree->left);
        left = tree->left->height;
    }
    if (tree->right)
    {
        binary_tree_update_heights(tree->right);
        right = tree->right->height;
    }

    tree->height = (left > right ? left : right) + 1;
}