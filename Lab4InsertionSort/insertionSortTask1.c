#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
} PERSON;

void insertionSort(PERSON A[], int n)
{
    for(int j = 1; j < n; j++)
    {
        insertInOrder(A[j], A, j);
    }
}

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



int main(){
    PERSON p1 = {1, "Sokka", 15, 150, 45};
    PERSON p2 = {2, "Aang", 112, 137, 35};
    PERSON p3 = {3, "Zuko", 16, 160, 50};
    PERSON p4 = {4, "Katara", 14, 145, 38};
    PERSON p5 = {5, "Toph", 12, 113, 30};

    PERSON arr[5]={p1,p2,p3,p4,p5};
    
    printf("Unsorted Array : \n");
    for(int i=0;i<5;i++){
        printf("%d %s %d %d %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
    insertionSort(arr,5);
    printf("Sorted Array by Height : \n");
    for(int i=0;i<5;i++){
        printf("%d %s %d %d %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
}