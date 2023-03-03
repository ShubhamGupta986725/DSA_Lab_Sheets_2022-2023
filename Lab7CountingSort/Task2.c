#include <stdio.h>
#include <stdlib.h>

int* counting_sort(int* A, int* B, int k, int n) 
{
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
    return B;
}

int main(){
    int n;
    FILE *ptr = fopen("n_integers.txt", "r");
    if(ptr==NULL){
        printf("Error.\n");
        return -1;
    }
    fscanf(ptr,"%d", &n);
    int* arr = malloc(n*sizeof(int));
    int* barr = malloc(n*sizeof(int));
    fscanf(ptr, ",[%d", &arr[0]);
    for(int i=1;i<n;i++){
        fscanf(ptr, " %d", &arr[i]);
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("\n");
    barr = counting_sort(arr, barr, max, n);
    printf("Enter the index you want to check : ");
    int sc;
    scanf("%d",&sc);

    printf("Enter the limits of the value : ");
    int a,b;
    scanf("%d %d", &a, &b);
    if(a<=barr[sc] && barr[sc]<=b){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    fclose(ptr);
    free(arr);
    free(barr);
}
