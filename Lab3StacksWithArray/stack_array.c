#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "element.h"


#define STACK_SIZE 1000
struct Stack
{
    int top;
    Element data[STACK_SIZE];
};

Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s!=NULL)
        s->top=-1;
    return s;
}

bool push(Stack *s, Element e)
{
    if(s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}

bool pop(Stack *s)
{
    if(s->top == -1)
        return false;
    s->top--;
    return true;
}

bool isEmpty(Stack *s){
    if(s->top == -1)
        return true;
    return false;
}

Element *top(Stack *s){
    if(s->top == -1)
        printf("Stack is empty\n");
    return &(s->data[s->top]);
}

void freeStack(Stack *s){
    free(s);
}

void printStack(Stack *s){
    for(int i=0;i<=s->top;i++){
        printf("%d ", s->data[i]);
    }
}

