#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=0, ans=0;
    STACK st = newStack();
    printf("Please enter size of operation : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char ch;
        scanf(" %c", &ch);
        if(isdigit(ch)){
            push(st, ch-'0');
        }
        else{
            int v1 = top(st);
            int v2 = top(pop(st));
            pop(st);
            if(ch=='+') push(st, v1+v2);
            if(ch=='-') push(st, v2-v1);
            if(ch=='*') push(st, v1*v2);
            if(ch=='/') push(st, v2/v1);
        }
    }
    printf("Answer = %d\n", top(st));   
}
