// Written by Kevin Chau on 24.01.2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "bst.h"


int main (void) {

    FILE *input = fopen("names.txt", "r");
    List list = new_list();

    char name[MAX_NAME_LEN];
    while (fgets(name, MAX_NAME_LEN, input) != NULL) {
        int len = strlen(name);
        if (name[len-2] = '\n') {
            name[len-2] = '\0';             // remove trailing newline
        }
        Node node = create_node(name);
        append_node(list, node);
    }

    Tree name_tree = create_empty_tree();
    Tree_rep data = create_rep(name_tree);          // Data collection
    name_tree = compare_list(list, name_tree, data);
    printf("\nYour selections ranked in order: \n");
    print_in_order(name_tree);
    printf("PRINTING IN LEVEL ORDER:\n");
    print_level_order(name_tree);
    printf("//////////////////\n");

    printf("\nNumber of comparisons: %d\n", data->num_comparisons);
    printf("Height of tree: %d\n", tree_height(name_tree));

    delete_list(list);
    delete_tree(name_tree);
    delete_tree_data(data);

    fclose(input);

    return 0;
}
