#include "stack.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define START_CAP 4

// Invariant: size <= capacity && capacity > 0
struct stack {
    size_t size;
    size_t capacity;
    void** stack;
};

// Returns 1 on error, 0 on success
int stack_mem_optimise(struct stack* stack) {
    size_t newCap;
    if (stack->size * 4 < stack->capacity) {
        newCap = stack->capacity / 2;
        if (newCap == 0) newCap = 1;
    } else if (stack->size + 1 > stack->capacity) {
        newCap = stack->capacity * 2;
    } else return 0;
    if (newCap == stack->capacity) return 0;
    void** newStack = realloc(stack->stack, newCap * sizeof(void *));
    if (newStack == NULL) return 1;
    stack->stack = newStack;
    printf("#%ld: %ld -> %ld\n", stack->size, stack->capacity, newCap);
    stack->capacity = newCap;
    return 0;
}

// stack.h

struct stack *stack_new() {
    struct stack *s = malloc(sizeof(struct stack));
    if (s != NULL) {
        s->size = 0;
        s->stack = calloc(START_CAP, sizeof(void*));
        if (s->stack == NULL) {
            free(s);
            return NULL;
        }
        s->capacity = START_CAP;
    }

    return s;
}

void stack_free(struct stack* stack) {
    assert(stack_empty((stack)));
    stack->capacity = 0;
    free(stack->stack);
    free(stack);
}

int stack_empty(struct stack* stack) {
    return stack->size == 0;
}

void* stack_top(struct stack* stack) {
    assert(!stack_empty(stack));
    return stack->stack[stack->size-1];
}

void* stack_pop(struct stack* stack) {
    void* ret = stack_top(stack);
    stack->size -= 1;
    return ret;
}

int stack_push(struct stack* stack, void* data) {
    stack->stack[stack->size] = data;
    stack->size += 1;
    stack_mem_optimise(stack);
    return 0;
}
