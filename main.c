
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
    name_tree = compare_list(list, name_tree);
    printf("\nYour selections ranked in order: \n");
    print_in_order(name_tree);

    fclose(input);

    return 0;
}
