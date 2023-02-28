#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int Ls[], int i1, int i2){
    int a = Ls[i1];
    int b = Ls[i2];
    Ls[i2] = a;
    Ls[i1] = b;
}

int threePart(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, hi - 1);
    int pivPos, lt, rt, mid, pv;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    pv = Ls[hi - 1];
    while (mid <= rt)
    {
        if (Ls[mid] < pv)
        {
            swap(Ls, lt, mid);
            lt++;
            mid++;
        }
        else if (Ls[mid] > pv)
        {
            swap(Ls, mid, rt);
            rt--;
        }
        else
        {
            mid++;
        }
    }
    swap(Ls, mid, hi - 1);
    return mid;
}

int main(){
    int arr[10] = {0,1,0,0,1,1,0,0,1,0};
    int arr1[10] = {0,1,0,0,1,1,0,0,1,1};

    threePart(arr, 0,9,9);
    for(int i=0;i<10;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    threePart(arr1, 0,9,9);
    for(int i=0;i<10;i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");

}