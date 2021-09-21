#include <stdlib.h>

#include "list.h"

struct list {
    void **data;
    size_t length;
    size_t capacity;
};

struct list *list_create() {
    struct list *list = realloc(NULL, sizeof(struct list));
    if (list != NULL) {
        list->data = NULL;
        list->length = 0;
        list->capacity = 0;
    }

    return list;
}

void list_free(struct list *list) {
    // We do not need to check for null
    free(list->data);
    free(list);
}

int list_insert_first(struct list *list, void *data) {
    if (list->length == list->capacity) {
        size_t newCap = (list->capacity == 0) ? 2 : (2 * list->capacity);

        // Do not need to check for null
        void **newData = realloc(list->data, newCap * sizeof(void *));

        if (newData == NULL) return 1;
        list->data = newData;
        list->capacity = newCap;
    }

    list->data[list->length++] = data;

    return 0;
}

int list_remove_first(struct list *list, void **dest) {
    if (list->length == 0) return 1;

    list->length--;
    *dest = list->data[list->length];

    return 0;
}

void list_map(struct list *list, map_fn f, void *aux) {
    for (size_t i = 0; i < list->length; i++) {
        f(list->data[i], aux);
    }
}
