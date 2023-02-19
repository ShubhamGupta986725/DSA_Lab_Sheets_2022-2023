#include <stdio.h>
#include <stdlib.h>

void mergeSort(int A[], int st, int en);
void mergeAuxR(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3);
void mergeAuxL(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3);
void merge(int A[], int s, int mid, int e);

int main(){
    int array[] = { 38, 27, 43, 3, 9, 82, 10};
    mergeSort(array, 0, 6);

    for(int i = 0; i < 7; i++){
        printf("%d\t", array[i]);
    }
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

void mergeAuxR(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3){

    if (s1 > e1 && s2 <= e2){
        L3[s3] = L2[s2];
        mergeAuxR(L1, s1, e1, L2, s2+1, e2, L3, s3+1, e3);
    }
    else if (s2 > e2 && s1 <= e1){
        L3[s3] = L1[s1];
        mergeAuxR(L1, s1+1, e1, L2, s2, e2, L3, s3+1, e3);
    }
    else if (s2 > e2 && s1 > e1){
        return;
    }
    else if (L1[s1] > L2[s2]){
        L3[s3] = L2[s2];
        mergeAuxR(L1, s1, e1, L2, s2+1, e2, L3, s3+1, e3);
    }
    
    else{
        L3[s3] = L1[s1];
        mergeAuxR(L1, s1 + 1, e1, L2, s2, e2, L3, s3 + 1, e3);
    }

}

void mergeAuxL(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3){
    int i,j,k;
    i=s1; j=s2; k=s3;
    while (i <= e1 && j <= e2) {
        if (L1[i] < L2[j])
            L3[k++] = L1[i++];
        else
            L3[k++] = L2[j++];
    }
    while (i <= e1)
        L3[k++] = L1[i++];
    while (j <= e2)
        L3[k++] = L2[j++];
}


void merge(int A[], int s, int mid, int e){
    int *C = (int *)malloc(sizeof(int) * (e - s + 1));
    mergeAuxR(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++){
        A[s + i] = C[i];
    }
    free(C); 
}