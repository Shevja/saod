#include "bstree.h"

struct bstree *bstree_create(char *key, int value)
{
    struct bstree *node;
    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = strdup(key);
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

void bstree_add(struct bstree *tree, char *key, int value)
{
    struct bstree *parent, *node;

    if (tree == NULL) {
        return;
    }

    /* Отыскиваем листовой узел */
    while (tree != NULL) {
        parent = tree;
        if (strcmp(key, tree->key) < 0) {
            tree = tree->left;
        } else if (strcmp(key, tree->key) > 0){
            tree = tree->right;
        } else {
            return;
        }
    }

    /* Создаем элемент и связываем с узлом */
    node = bstree_create(key, value);
    if (strcmp(key, parent->key) < 0) {
        parent->left = node;
    }
    else {
        parent->right = node;
    }
}

struct bstree *bstree_lookup(struct bstree *tree, char* key)
{
    while (tree != NULL) {
        if (strcmp(key, tree->key) == 0) {
            return tree;
        } else if (strcmp(key, tree->key) < 0) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    return tree;
}

struct bstree *bstree_min(struct bstree *tree)
{
    if (tree == NULL) {
        return NULL;
    }

    while (tree->left != NULL) {
        tree = tree->left;
    }

    return tree;
}

struct bstree *bstree_max(struct bstree *tree)
{
    if (tree == NULL) {
        return NULL;
    }

    while (tree->right != NULL) {
        tree = tree->right;
    }

    return tree;
}