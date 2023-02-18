#include <stdbool.h>
#include "linked_list.h"
STACK newStack();
// Returns a pointer to a new stack. Returns NULL if memory allocation fails

bool push(STACK stack, int element);
// Pushes element onto stack. Returns false if memory allocation fails

int top(STACK stack);
// Returns a pointer to the top element. Returns NULL if stack is empty

STACK pop(STACK stack);
// Pops the top element and returns true. Returns false if stack is empty

bool isEmpty(STACK stack);
// Returns true if stack is empty. Returns false otherwise

void freeStack(STACK stack);
// Frees all memory associated with stack
