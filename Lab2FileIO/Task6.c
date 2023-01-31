#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp1 = fopen("text1.txt", "r+");
    FILE *fp2 = fopen("text2.txt", "a+");
    if(fp1==NULL){
        printf("FP1 is NULL");
        return -1;
    }
    if(fp2==NULL){
        printf("FP2 is NULL");
        return -1;
    }

    char str[1000];
    while(fgets(str,1000,fp1)!=NULL){
        fprintf(fp2,"%s",str);
    }
    fclose(fp1);
    fp1=fopen("text1.txt", "w");
    fclose(fp1);
    fclose(fp2);

}