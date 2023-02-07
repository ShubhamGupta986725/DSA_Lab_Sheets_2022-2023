#ifndef STACK2_H
#define STACK2_H
#include <stdbool.h>
#include "element.h"
typedef struct Stack Stack; // Stack is a pointer to a struct stack
Stack *newStack();
// Returns a pointer to a new stack. Returns NULL if memory allocation fails

Stack* push(Stack *stack, Element element);
// Pushes element onto stack. Returns false if memory allocation fails

Element *top(Stack *stack);
// Returns a pointer to the top element. Returns NULL if stack is empty

Stack* pop(Stack *stack);
// Pops the top element and returns true. Returns false if stack is empty

bool isEmpty(Stack *stack);
// Returns true if stack is empty. Returns false otherwise

void freeStack(Stack *stack);
// Frees all memory associated with stack

#endif

