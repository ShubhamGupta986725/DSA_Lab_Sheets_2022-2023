#include <stdio.h>
#include <stdlib.h>



typedef struct node* NODE;
struct node{
    int val;
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
    myNode->val=value;
    myNode->next=NULL;
    return myNode;
}

void deleteFirstNode(LIST l){
    if(l->count==0){
        printf("List Empty, nothing to delete.\n");
        return;
    }
    else{
        NODE t = l->head;
        l->head = t->next;
        free(t);
        l->count--;
    }
}

void insertAtEnd(LIST l, int e){
    if(l->count==0){
        NODE x = createNewNode(e);
        l->head = x;
        x->next=NULL;
        l->count++;
        return;
    }
    NODE n = l->head;
    while(n->next!=NULL){
        n=n->next;
    }
    NODE ele = createNewNode(e);
    n->next = ele;
    ele->next=NULL;
    l->count++;
}

void BucketSort(int* arr, int n){
    int max=0;
    for(int i=0;i<n;i++){
        if (arr[i]>max) max=arr[i];
    }

    LIST a[max+1];
    for(int i=0;i<max+1;i++){
        a[i] = createNewList();
    }
    for(int i=0;i<n;i++){
        insertAtEnd(a[arr[i]], arr[i]);
    }

    int i=0;
    for(int j=0;j<max+1;j++){
        // printf("j = %d , count = %d", j, a[j]->count);
        // printList(a[j]);
        // printf("\n");
        if(a[j]->count!=0){
            NODE n = a[j]->head;
            if(a[j]->count==1){
                arr[i] = n-> val;
                i++;
            }
            else{
                while(n->next!=NULL){
                arr[i] = n->val;
                n=n->next;
                i++;
            }}
        }
    }
}

  
void printList(LIST l1){
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while(temp != NULL)
    {
        printf(" %d ->", temp->val);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}

int main(){
    int ch[] = {50, 34, 22, 43, 12, 35};
    BucketSort(ch, 6);
    for(int i=0;i<6;i++){
        printf("%d ", ch[i]);
    }
}