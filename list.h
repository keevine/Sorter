#ifndef LIST_H
#define LIST_H

#define MAX_NAME_LEN 32

struct list_rep {
    struct list_node *head;
    struct list_node *tail;
    int size;
};

typedef struct list_rep *List;

struct list_node {
    char name[MAX_NAME_LEN];
    struct list_node *next;
};

typedef struct list_node *Node;

List new_list (void);
Node create_node (char name[MAX_NAME_LEN]);
void append_node (List L, Node n);
void show_list (List L);



#endif
