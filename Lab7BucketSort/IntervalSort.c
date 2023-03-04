#include <stdio.h>
#include <stdlib.h>
typedef struct node* NODE;
struct node{
    int ele;
    NODE next;
};

typedef struct linked_list* LIST;
struct linked_list{
    int count;
    NODE head;
};


LIST createNewList()
{
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}

NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->ele=value;
    myNode->next=NULL;
    return myNode;
}
void insertAfter(int searchEle, NODE n1, LIST l1){
    if(l1->head==NULL)
    {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else
    {
        NODE temp = l1->head;
        NODE prev = temp;
        while(temp!=NULL)
        {
            if (temp->ele == searchEle)
            break;
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL)
        {
            printf("Element not found\n");
            return;
        }
        else
        {
            if(temp->next == NULL){
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }
            else{
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}




void insertFirst(NODE n1, LIST l1){
    if(l1->count==0){
        l1->head = n1;
        n1->next=NULL;
        l1->count++;
    }
    else{
        n1->next=l1->head;
        l1->head=n1;
        l1->count++;
    }
}

void intervalSort(float arr[], int n)
{
    int i, j;
    LIST b[n];
    for(i=0; i<n; i++)
    {
        b[i] = createNewList();
    }
    for(i=0; i<n; i++){
        insertFirst(b[(int)(n*arr[i])], createNewNode(arr[i]));
    }
    for(i=0; i<n; i++)
    {
       sortList(b[i]);
    }
    for(i=0, j=0; i<n; i++){
        NODE temp = b[i]->head;
        while(temp != NULL)
        {
            arr[j++] = temp->ele;
            temp = temp->next;
        }
    }
}

int main(){
    float arr[] = {9837, 2617, 8273, 1928, 8189, 2910, 6384, 2891, 1029, 2933};
    intervalSort(arr, 11);
    for(int i=0;i<11;i++){
        printf("%d ", arr[i]);
    }
}