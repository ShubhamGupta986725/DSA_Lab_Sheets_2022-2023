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
    int arr[] = {5775, 6252, 9884, 2910, 3615, 3974, 1527, 3732, 1928};
    int barr[9];
    radix_sort(arr, barr, 9);
    for(int i=0;i<9;i++){
        printf("%d ", barr[i]);
    }
}
