#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

STACK newStack(){
    STACK s = createNewList();
    if(s==NULL) return NULL;
    return s;
}

bool push(STACK stack, element element){
    NODE e = createNewNode(element);
    if(e==NULL) return false;
    insertNodeIntoList(e, stack);
    return true;
}

element *top(STACK stack){
    if(stack->count==0) return NULL;
    return stack->head;
}

bool pop(STACK stack){
    if(stack->count==0) return false;
    removeFirstNode(stack);
    return true;
}

bool isEmpty(STACK stack){
    if(stack->count==0) return true;
    return false;
}

void freeStack(STACK stack){
    free(stack);
}

