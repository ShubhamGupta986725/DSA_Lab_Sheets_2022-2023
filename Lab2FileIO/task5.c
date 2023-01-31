#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen(__FILE__, "r");
    if(fp!=NULL){
    char s[100000];
        while(EOF!=fscanf(fp, "%100000[^\n]\n", s)){
            printf("%s\n", s);
        }
        fclose(fp);
        // char st[1000];
        // while(fgets(st,1000,fp)!=NULL){
        //     printf("%s", st);
        // }
        // fclose(fp);

        
    }
}