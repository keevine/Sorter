#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bst.h"
#include "list.h"

Tree create_empty_tree (void) {
    return NULL;
}

Tree create_tree_node (Node node) {
    Tree tree_node = malloc(sizeof(struct tree_node));
    tree_node->node = node;
    tree_node->left = NULL;
    tree_node->right = NULL;
    return tree_node;
}

// Given a node with an input name, request the user to choose which one is better
// and insert accordingly.
// If user prefers node over the items in the tree, insert left
// If user prefers items in tree over node, insert right
Tree insert_tree_node (Tree T, Node node) {
    if (T == NULL) {
        // empty tree
        return create_tree_node(node);
    } else {
        if (prompt(T, node) == 1) {
            T->left = insert_tree_node(T->left, node);
        } else if (prompt(T, node) == 2) {
            T->right = insert_tree_node(T->right, node);
        }
    }
    return T;
}

int prompt (Tree T, Node node) {
    char name[MAX_NAME_LEN];
    strncpy(name, T->node->name, MAX_NAME_LEN);
    printf("Select the best option out of the two: (Enter the number 1 or 2)\n");
    printf("\t1) %s\n", node->name);
    printf("\t2) %s\n", name);

    int input = 0;
    while (input != 1 || input != 2) {
        scanf("%d", &input);
        if (input != 1 || input != 2) {
            printf("Error - didn't enter the number 1 or 2. Try again.\n");
        }
    }

    return input;
}

void print_in_order (Tree T) {
    if (T == NULL) {
        return;
    }
    print_in_order(T->left);
    printf("%s\n", T->node->name);
    print_in_order(T->right);
}
