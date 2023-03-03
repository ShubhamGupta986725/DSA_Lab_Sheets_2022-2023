#include <stdio.h>
#include <stdlib.h>
int* counting_sort(int* A, int* B, int n, int place) 
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

int main(){
    int arr[] = {5775, 6252, 9884, 2910, 3615, 3974, 1527, 3732, 1928};
    int barr[9];
    counting_sort(arr, barr, 9, 100);
    for(int i=0;i<9;i++){
        printf("%d ", barr[i]);
    }
}