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
    for(int i=0;i<x;i++)
    {
        printf("%d\n", p[i]);
    }
    printf("Reallocating Memory now.");
    p=realloc(p, 2*x*sizeof(int));
    for(int i=0;i<2*x;i++){
        p[i]=i*i;
    }
    for(int i=0;i<x*2;i++)
    {
        printf("%d\n", p[i]);
    }
    free(p);
}