#include "IntMerge.h"
#include "IntMergeAux.h"

void IntMerge(int arr[], int start, int mid, int end){
    int start2 = mid + 1;
    if (arr[mid] <= arr[start2]) {
        return;
    }
    while (start <= mid && start2 <= end) {
        IntMergeAuxIter(arr, start, mid, end);
    }
}