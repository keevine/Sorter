#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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
Tree insert_tree_node (Tree T, Node node, Tree_rep data) {
    if (T == NULL) {
        // empty tree
        return create_tree_node(node);
    } else {
        int input = prompt(T, node, data);
        if (input == 1) {
            T->left = insert_tree_node(T->left, node, data);
        } else if (input == 2) {
            T->right = insert_tree_node(T->right, node, data);
        }
    }
    return T;
}

int prompt (Tree T, Node node, Tree_rep data) {
    char name[MAX_NAME_LEN];
    strncpy(name, T->node->name, MAX_NAME_LEN);
    printf("Select the best option out of the two: (Enter the number 1 or 2)\n");
    printf("\t1) %s\n", node->name);
    printf("\t2) %s\n", name);

    int input = 0;
    while (input != 1 && input != 2) {
        scanf("%d", &input);
        if (input != 1 && input != 2) {
            printf("Error - didn't enter the number 1 or 2. Try again.\n");
        }
    }
    data->num_comparisons++;
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

// Returns the maximum height of the tree and stores in the tree rep struct
int tree_height (Tree T) {
    // base case
    if (T == NULL) {
        return 0;
    }
    int left_height = tree_height(T->left);
    int right_height = tree_height(T->right);
    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}

Tree_rep create_rep (Tree T) {
    Tree_rep data = malloc(sizeof(struct tree_rep));
    data->root = T;
    data->height = tree_height(T);
    data->num_comparisons = 0;
}

void delete_tree (Tree T) {
    if (T == NULL) {
        // base case
        return;
    }
    delete_tree(T->left);
    delete_tree(T->right);
    free(T);
}

void delete_tree_data (Tree_rep data) {
    assert(data != NULL);
    free(data);
}

void print_level_order (Tree T) {
    int height = tree_height(T);
    for (int i = 0; i <= height; i++) {
        printf("LEVEL %d\n", i);
        print_given_level(T, i);
        printf("\n");
    }
}

void print_given_level (Tree T, int level) {
    if (T == NULL) {
        return;
    }
    if (level == 1) {
        // printing the root node
        printf("%s -> ", T->node->name);
    } else if (level > 1){
        // printing all subtrees
        print_given_level(T->left, level - 1);
        print_given_level(T->right, level - 1);
    }
}

Tree rotate_right (Tree T) {
    Tree sub_left = T->left;
    Tree sub_left_right = sub_left->right;

    sub_left->right = T;
    T->left = sub_left_right;

    return sub_left;
}

Tree rotate_left (Tree T) {
    Tree sub_right = T->right;
    Tree sub_right_left = sub_right->left;

    sub_right->left = T;
    T->right = sub_right_left;

    return sub_right;
}

void check_balanced_tree (Tree T) {
    if (T == NULL) {
        return;
    } else if (tree_height(T->left) - tree_height(T->right) >= 2) {
        T = rotate_right(T);
    } else if (tree_height(T->right) - tree_height(T->left) >= 2) {
        T = rotate_left(T);
    }
    check_balanced_tree(T->left);
    check_balanced_tree(T->right);
}
