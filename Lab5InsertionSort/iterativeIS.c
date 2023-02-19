#include <stdio.h>

void iterativeIS(int *arr, int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[]={4,3,6,9,10,3,6,2,8};
    iterativeIS(arr, 9);
    for(int i=0;i<9;i++){
        printf("%d ", arr[i]);
    }
}