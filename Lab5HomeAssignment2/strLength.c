#include <stdio.h>

int lengthNTR(char *str)
{
    if (*str == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + lengthNTR(str + 1);
    }
}

int lengthTR(char *str, int acc){
    if(*str == '\0'){
        return acc;
    }
    else{
        return lengthTR(str+1, acc+1);
    }
}

int lengthI(char *str){
    int acc=0;
    while(*(str+acc)!='\0'){
        acc++;
    }
    return acc;

}

int main(){
    char arr[]="Shubham";
    printf("NTR%d   TR%d   I%d", lengthNTR(arr), lengthTR(arr, 0), lengthI(arr));
}