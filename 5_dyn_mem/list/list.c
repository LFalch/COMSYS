#include "list.h"
#if USE_ARRAY == 1

#include "list_array.c"

#else

#include <stdlib.h>

struct list_node {
    void *data;
    struct list_node *next;
    struct list_node *prev;
};

struct list {
    struct list_node *head;
    struct list_node *last;
};

struct list *list_create() {
    struct list *list = malloc(sizeof(struct list));
    if (list != NULL) {
        list->head = NULL;
        list->last = NULL;
    }

    return list;
}

void list_free(struct list *list) {
    struct list_node *node = list->head;
    while (node != NULL) {
        struct list_node *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

int list_insert_first(struct list *list, void *data) {
    struct list_node *new_head = malloc(sizeof(struct list_node));
    new_head->data = data;
    new_head->next = list->head;
    new_head->prev = NULL;

    if(list->head != NULL) list->head->prev = new_head;
    list->head = new_head;
    if (list->last == NULL) list->last = list->head;
    return 0;
}

int list_remove_first(struct list *list, void **dest) {
    struct list_node *old_head = list->head;
    if (old_head == NULL) {
        return 1;
    }
    *dest = old_head->data;
    list->head = old_head->next;
    free(old_head);
    if (list->head == NULL) list->last = NULL;
    return 0;
}

void list_map(struct list *list, map_fn f, void *aux) {
    struct list_node *node = list->head;
    while (node != NULL) {
        node->data = f(node->data, aux);
        node = node->next;
    }
}

#endif