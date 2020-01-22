
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


int main (void) {

    FILE *input = fopen("names.txt", "r");
    List list = new_list();

    char name[MAX_NAME_LEN];
    while (fgets(name, MAX_NAME_LEN, input) != NULL) {
        int len = strlen(name);
        if (name[len-2] = '\n') {
            name[len-2] = '\0';             // remove trailing newline
        }
        printf("name is %s\n", name);
        Node node = create_node(name);
        append_node(list, node);
    }

    show_list(list);




    /*
    Node node = create_node("first");
    append_node(list, node);
    Node nodee = create_node("second");
    append_node(list, nodee);
    Node third = create_node("testing asdasd");
    append_node(list, third);
    show_list(list);
    */
    fclose(input);

    return 0;
}
