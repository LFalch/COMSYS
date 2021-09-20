#ifndef STACK_H
#define STACK_H

struct stack;

// Returns NULL if malloc fails
struct stack* stack_new();

// Precondition: stack should be empty
void stack_free(struct stack*);

// True if empty, false is not empty
int stack_empty(struct stack*);

// Precondtion: stack is not empty
void* stack_top(struct stack*);

// Precondtion: stack is not empty
void* stack_pop(struct stack*);

// Returns 1, if we can't expand the stack, 0 on success
int stack_push(struct stack*, void*);


#endif
