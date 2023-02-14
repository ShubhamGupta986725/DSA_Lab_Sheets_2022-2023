#include <stdio.h>
#include <stdlib.h>

void mergeAux(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3){
    
    if(s1>e1 && s2>e2){
        return;
    }
    if(s2>e2){
        L3[s3]=L1[s1];
        mergeAux(L1, s1+1, e1, L2, s2 , e2, L3, s3 + 1, e3);
        return;
    }

    if(s1>e1){
        L3[s3]=L2[s2];
        mergeAux(L1, s1, e1, L2, s2+1 , e2, L3, s3 + 1, e3);
        return;
    }

    
    if (L1[s1] > L2[s2]){
        L3[s3] = L2[s2];
        mergeAux(L1, s1, e1, L2, s2 + 1, e2, L3, s3 + 1, e3);
    }
    else{
        L3[s3] = L1[s1];
        mergeAux(L1, s1 + 1, e1, L2, s2, e2, L3, s3 + 1, e3);
    }
}

void merge(int A[], int s, int mid, int e)
{
    int *C = (int *)malloc(sizeof(int) * (e - s + 1));
    mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++)
    {
        A[s + i] = C[i];
    }
    free(C);
}

void mergeSort(int A[], int st, int en)
{
    if (en - st < 1)
        return;
    int mid = (st + en) / 2;
    mergeSort(A, st, mid);
    mergeSort(A, mid + 1, en);
    merge(A, st, mid, en);
}

int main(){
    int arr[10]={32, 65, 43, 12, 00, 76, 92, 76, 15, 36};
    mergeSort(arr, 0, 9);
    for(int i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}