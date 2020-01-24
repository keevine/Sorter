#ifndef BST_H
#define BST_H

#include "list.h"

struct tree_node {
    Node node;
    struct tree_node *left;
    struct tree_node *right;
};

typedef struct tree_node *Tree;

struct tree_rep {
    Tree root;
    int height;
    int num_comparisons;
};

typedef struct tree_rep *Tree_rep;


Tree create_empty_tree (void);
Tree create_tree_node (Node node);
Tree insert_tree_node (Tree T, Node node, Tree_rep data);
int prompt (Tree T, Node node, Tree_rep data);
void print_in_order (Tree T);
int tree_height (Tree T);
Tree_rep create_rep (Tree T);
void delete_tree (Tree T);
void delete_tree_data (Tree_rep data);


#endif
