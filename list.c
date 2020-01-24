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

Tree compare_list (List L, Tree T, Tree_rep data) {
    Node curr = L->head;
    while (curr != NULL) {
        T = insert_tree_node(T, curr, data);

        curr = curr->next;
    }
    return T;
}

Node get_prev_tail (List L) {
    assert(L != NULL);
    if (L->size == 0 || L->size == 1) {
        // There is no previous node if only one or no items exist in the list
        return NULL;
    }
    Node curr = L->head;
    while (curr->next != L->tail) {
        // loop until curr's next is the last item
        curr = curr->next;
    }
    return curr;
}

void remove_tail (List L) {
    if (L->size == 0) {
        // empty list
        return;
    } else if (L->size == 1) {
        // single element in list
        L->tail = NULL;
        L->head = NULL;
    } else {
        Node prev = get_prev_tail(L);
        L->tail = prev;
        prev->next = NULL;
    }
    free(L->tail);
    L->size--;
}

void delete_list (List L) {
    assert(L != NULL);
    while (L->size > 0) {
        remove_tail(L);
    }
    free(L);
}
