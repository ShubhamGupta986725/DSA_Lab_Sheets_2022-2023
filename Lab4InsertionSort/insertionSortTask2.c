#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

typedef struct person
{
    int id;
    char name[100];
    int age;
    int height;
    int weight;
} PERSON;

void insertInOrder(PERSON v,PERSON A[], int last)
{
    int j = last - 1;
    while(j >= 0 && v.height < A[j].height)
    {
        A[j+1] = A[j];
        j--;
    }
    A[j+1] = v;
}

void insertionSort(PERSON A[], int n)
{
    for(int j = 1; j < n; j++)
    {
        insertInOrder(A[j], A, j);
    }
}

int main(){
    
    FILE *fptr;
    fptr = fopen("dat10000.csv", "r");
    if(fptr==NULL){
        printf("File not found\n");
        return 0;
    }
    PERSON arr[10000];
    int i=0;
    while(fscanf(fptr, "%d,%[^,],%d,%d,%d\n", &(arr[i].id), arr[i].name, &(arr[i].age), &(arr[i].height), &(arr[i].weight))!=-1){
        i++;
    }
    fclose(fptr);

    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    insertionSort(arr,10000);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    
    printf("Time taken for 1000 data values = %f\n", time_taken);
}