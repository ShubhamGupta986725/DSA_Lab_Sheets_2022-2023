#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void swap(int Ls[], int i1, int i2){
    int a = Ls[i1];
    int b = Ls[i2];
    Ls[i2] = a;
    Ls[i1] = b;
}

int part(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt)
    {
        for (; lt <= hi && Ls[lt] <= pv; lt++);
        for (; Ls[rt] > pv; rt--);
        if (lt < rt)
        {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt] < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(Ls, lo, pivPos);
}

int qselect(int L[], int n, int k)
{
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;
    int pInd = part(L, lo, hi, pivot);
    if (k <= pInd)
        return qselect(L, pInd, k);
    else if (k > pInd + 1)
        return qselect(L + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return L[pInd];
}

int main(){
    int arr[] = {1,3,5,7,9};
    double size=5.0f;
    int k=3;
    // int med = qselect(arr, size, ceil(size/2.0));
    int arrMed[6];
    // for(int i=0;i<2*k;i++){
    //     arrMed[i] = qselect(arr, size, ceil(size/2.0) + k - i);
    //     arrMed[i] -= med;
    // }
    // for(int i=0;i<k;i++){
    //     printf("%d ", qselect(arrMed, 2*k, i+1));
    // }

}