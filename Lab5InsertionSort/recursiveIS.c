#include <stdio.h>

void recursiveIS(int *arr, int n){
    if(n<=1) return;
    recursiveIS(arr, n-1);
    int key=arr[n-1];
    int j=n-2;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}

int main(){
    int arr[]={4,3,6,9,10,3,6,2,8};
    recursiveIS(arr, 9);
    for(int i=0;i<9;i++){
        printf("%d ", arr[i]);
    }
}