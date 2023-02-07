#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"
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

Stack* push(Stack *s, Element e)
{
    if(s->top == STACK_SIZE - 1)
        return s;
    s->data[++(s->top)] = e;
    return s;
}

Stack* pop(Stack *s)
{
    if(s->top == -1)
        return s;
    s->top--;
    return s;
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
