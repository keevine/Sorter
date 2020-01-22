#ifndef BST_H
#define BST_H

#include "list.h"

struct tree_node {
    Node node;
    struct tree_node *left;
    struct tree_node *right;
};

typedef struct tree_node *Tree;

Tree create_empty_tree (void);
Tree create_tree_node (Node node);
Tree insert_tree_node (Tree T, Node node);
int prompt (Tree T, Node node);
void print_in_order (Tree T);


#endif
