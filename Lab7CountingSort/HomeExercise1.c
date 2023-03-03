#include <stdio.h>
#include <stdlib.h>

void counting_sort(int* A, int* B, int k, int n) 
{
    printf("\n");
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }
    for (int j = 0; j < n; j++) 
    {
        C[A[j]]++;
    }
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main(){
    FILE *ptr = fopen("heights.txt", "r");
    if(ptr==NULL){
        printf("Error opening file");
        return -1;
    }
    int currRow=1;
    // while(!feof){
        int size;
        fscanf(ptr, "%d", &size);
        // printf("size=%d", size);
        int* curr = malloc(size*sizeof(int));
        int* expe = malloc(size*sizeof(int));
        fscanf(ptr, ",[%d", &curr[0]);
        for(int i=1;i<size;i++){
            fscanf(ptr, ", %d", &curr[i]);
        }
        fscanf(ptr, "]\n");
        int k=0;
        for(int i=0;i<size;i++){
            if(curr[i]>k) k=curr[i];
        }
        printf("k = %d", k);
        counting_sort(curr, expe, k, size);
        int wrong=0;
        for(int i=0; i<size;i++){
            if(expe[i]!=curr[i]){
                wrong++;
            }
        }

        for(int i=0;i<size;i++){
            printf("curr = %d; expe = %d\n", curr[i], expe[i]);
        }
        // printf("Row %d has %d mismatches.", currRow, wrong);
        // currRow++;
        free(curr);
        free(expe);
    // }
        fclose(ptr);
}