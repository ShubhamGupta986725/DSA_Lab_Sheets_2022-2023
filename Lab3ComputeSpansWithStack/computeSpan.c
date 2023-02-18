#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
void computeSpans(int *inputs, int *spans, int n);

int main()
{
    int inputs[] = {6, 3, 4, 5, 2};
    int spans[5]={0};
    computeSpans(inputs, spans, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", spans[i]);
    }
    printf("\n");
    int inputs2[] = {100, 80, 60, 70, 60, 75, 85};
    int spans2[7]={0};
    computeSpans(inputs2, spans2, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", spans2[i]);
    }
    printf("\n");
    return 0;
}

void computeSpans(int *inputs, int *spans, int n)
{
    STACK s1=newStack();
    push(s1,0);
    *(spans+0)=1;
    for(int i=1;i<n;i++){
        // printf("top%d   %d   ",top(s1), *(inputs+i));
        while(!isEmpty(s1) && *(inputs+top(s1))<=*(inputs+i)){
            pop(s1);
        }
        if(isEmpty(s1)){
            *(spans+i)=i+1;
        }
        else{
            *(spans+i)=i-top(s1);
        }
        push(s1, i);
    }
    freeStack(s1);
}