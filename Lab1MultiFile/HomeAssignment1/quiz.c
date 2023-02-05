#include <stdio.h>
#include <string.h>
#include "set.h"


int main(){
    char studAns[11];
    for(int i=0;i<10;i++){
        printf("Enter answers for question number %d:", i+1);
        char c,d;
        scanf(" %c", &c);
        studAns[i]=c;
    }
    printf("%d",answer_checker(studAns));
}