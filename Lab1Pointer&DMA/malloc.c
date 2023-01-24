#include <stdio.h>
#include <stdlib.h>

int main(){
    int x=10;
    int *p = (int *)malloc(x*sizeof(int));
    if(p==NULL){
        printf("Memory allocation failed.");
        return -1;
    }
    for(int i=0;i<x;i++){
        p[i]=i*i;
    }
    for(int i = 0; i < x; i++)
    {
        printf("%d\n", p[i]);
    }
    free(p);
}