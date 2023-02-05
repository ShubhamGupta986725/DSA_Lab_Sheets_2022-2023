#include <stdio.h>
#include <string.h>
#include "set.h"

int answer_checker(char *ptr){
    char correctAnswers[] = {'A','C','B','D','A','C','B','D','A','C'};
    int marks=0;
    for(int i=0;i<10;i++){
        if(*(ptr+i) == correctAnswers[i]){
            marks+=4;
        }
        else if(*(ptr+i) == 'N'){
            marks+=0;
        }
        else{
            marks-=1;
        }
    }
    if(marks<0){
        return 0;
    }
    else{
        return marks;
    }

}