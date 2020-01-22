#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "list.h"
#include "bst.h"

List new_list (void) {
    List new = malloc(sizeof(struct list_rep));
    new->head = NULL;
    new->tail = NULL;
    new->size = 0;
    return new;
}

Node create_node (char name[MAX_NAME_LEN]) {
    Node new = malloc(sizeof(struct list_node));
    strncpy(new->name, name, MAX_NAME_LEN);
    new->next = NULL;
}

void append_node (List L, Node n) {
    assert(L != NULL);
    assert(n != NULL);
    if (L->head == NULL && L->tail == NULL) {
        // empty list
        L->head = n;
        L->tail = n;
    } else if (L->head == L->tail) {
        // exactly one element in list
        L->head->next = n;
        L->tail = n;
        L->tail->next = NULL;
    } else {
        // more than one element in list
        L->tail->next = n;
        L->tail = n;
        L->tail->next = NULL;
    }
    L->size++;
}

void show_list (List L) {
    Node curr = L->head;
    while (curr != NULL) {
        printf("%s -> ", curr->name);
        curr = curr->next;
    }
    printf("X\n");
}

void compare_list (List L, Tree T) {
    Node curr = L->head;
    while (curr != NULL) {
        insert_tree_node(T, curr);
        curr = curr->next;
    }
}
