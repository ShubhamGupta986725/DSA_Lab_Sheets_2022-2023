#include <stdio.h>

int Recfibonacci(int n){
    if(n<=0){
        return -1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 1;
    }
    return Recfibonacci(n-1)+Recfibonacci(n-2);
}

int Iterfibonacci(int n){
    if(n<=0) return -1;
    if(n==1) return 1;
    if(n==2) return 1;
    int ans=1;
    int prev=1;
    for(int i=0;i<n-2;i++){
        int temp=prev;
        prev=ans;
        ans+=temp;
    }
    return ans; 
}