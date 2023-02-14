#include "IntMergeAux.h"

void IntMergeAuxIter (int arr[], int start, int mid, int end){
    int start2 = mid+1;
    if (arr[start] <= arr[start2]) {
        start++;
    }
    else {
        int value = arr[start2];
        int index = start2;
        while (index != start) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[start] = value;
        start++;
        mid++;
        start2++;
    }
}

