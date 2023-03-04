#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* radix_straight_aux(int* A, int* B, int n, int place) 
{
    int k=10;
    int C[k];
    for (int i = 0; i < k; i++){
        C[i] = 0;
    }
    for (int j = 0; j < n; j++){
        int x = A[j]/place;
        C[x%10]++;
    }
    for (int i = 1; i < k; i++){
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--){
        int x = A[j]/place;
        B[C[x%10] - 1] = A[j];
        C[x%10]--;
    }
    return B;
}

int* radix_sort(int* A, int* B, int n){
    int place=1;
    int max=0;
    for(int i=0;i<n;i++) if(A[i]>max) max=A[i];
    int iter=log10(max)+1;
    for(int i=0;i<iter;i++){
        radix_straight_aux(A, B, n, place);   
        for(int i=0;i<n;i++){
            A[i]=B[i];
        }
        place*=10;        
    }
    return A;
}

int main(){
    FILE *ptr = fopen("n_integers.txt", "r+");
    if(ptr==NULL){
        printf("File couldn't be opened.\n");
        return -1;
    }

    while(!feof(ptr)){
        int num;
        fscanf(ptr,"%d", &num);
        int arr[num];
        fscanf(ptr,",[%d", &arr[0]);
        for(int i=1;i<num;i++){
            fscanf(ptr, " %d", &arr[i]);
        }
        int diff[num-1];
        for(int i=0;i<num-1;i++){
            diff[i]=abs(arr[i+1]-arr[i]);
        }

        int sortedDiff[num-1];
        radix_sort(diff, sortedDiff, num-1);
        printf("Highest Diff = %d\n", sortedDiff[num-2]);
        fscanf(ptr, "] ");
    }

    fclose(ptr);
}