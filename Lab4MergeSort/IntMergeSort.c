#include <stdio.h>
#include <stdlib.h>
#include "IntMerge.h"
#include "IntMergeAux.h"

void mergeSort(int arr[], int st, int en){
    if (en - st < 1)
        return;
    int mid = (st + en) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, en);
    IntMerge(arr, st, mid, en);
}

int main(){
    int arr[] = {1,4,3,5};
    mergeSort(arr, 0, 3);
    for(int i=0;i<4;i++){
        printf("%d ", arr[i]);
    }
}