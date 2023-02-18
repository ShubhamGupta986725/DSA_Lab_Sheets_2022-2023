#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

STACK newStack(){
    STACK s = createNewList();
    if(s==NULL) return NULL;
    return s;
}

bool push(STACK stack, int ch){
    NODE e = createNewNode(ch);
    if(e==NULL) return false;
    insertNodeIntoList(e, stack);
    return true;
}

int top(STACK stack){
    if(stack->count==0) return -1000000;
    return (stack->head)->val;
}

STACK pop(STACK stack){
    if(stack->count==0) return stack;
    removeFirstNode(stack);
    return stack;
}

bool isEmpty(STACK stack){
    if(stack->count==0) return true;
    return false;
}

void freeStack(STACK stack){
    free(stack);
}

