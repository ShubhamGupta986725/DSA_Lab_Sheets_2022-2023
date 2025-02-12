#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    
void printList(LIST l1)
    {
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while(temp != NULL)
    {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}

void deleteAt(LIST l1, int n){
    if(n>l1->count){
        printf("List size too small for this size\n");
        return;
    }
    else if(l1->count==0){
        printf("List is Empty\n");
        return;
    }
    else{
        NODE temp = l1->head->next;
        NODE prev = l1->head;    
        for(int i=0;i<n-2;i++){
            temp=temp->next;
            prev=prev->next;
        }
        prev->next = temp->next;
        temp->next=NULL;
        l1->count--;
        free(temp);
    }
}

void insertAtBeginning(NODE n1, LIST l1){
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

int search(int x, LIST l){
    if(l->count==0){
        printf("List is Empty.\n");
        return -1;
    }
    else{
        NODE temp=l->head;
        int pos=1;
        while(temp->next!=NULL){
            if(temp->ele==x){
                printf("ELEMENT FOUND AT POSITION %d\n", pos);
                return pos;
            }
            else{
                temp=temp->next;
                pos++;
            }
        }
        printf("ELEMENT NOT FOUND\n");
        return -1;
    }
}

void rotate(int k, LIST l){
    if(l->count==0){
        printf("List is empty, nothing to rotate.\n");
        return;
    }
    else{
        NODE last=l->head;
        NODE kth=l->head;
        while(last->next!=NULL){
            last=last->next;
        }
        for(int i=0;i<k-1;i++){
            kth=kth->next;
        }
        NODE nextk = kth->next;
        last->next = l->head;
        l->head=nextk;
        kth->next=NULL;
        return;
    }
}

bool hasCycle(LIST l){

    if(l->count==0){
        printf("List is empty, cycle can not be possible.\n");
        return false;
    }
    else{
        NODE hare = l->head->next;
        NODE tortoise = l->head;
        while(hare->next!=NULL && tortoise->next!=NULL && hare->next->next!=NULL){
            if(hare==tortoise){
                printf("Cycle detected.\n");
                return true;
            }
            else{
                hare=hare->next->next;
                tortoise=tortoise->next;
            }
        }
        printf("No Cycle detected.\n");
        return false;
    }
}

int main(){
    LIST l = createNewList();
    NODE n1 = createNewNode(10);
    insertAtBeginning(n1, l);
    NODE n2 = createNewNode(9);
    insertAtBeginning(n2, l);
    NODE n3 = createNewNode(8);
    insertAtBeginning(n3, l);
    NODE n4 = createNewNode(7);
    insertAtBeginning(n4, l);
    NODE n5 = createNewNode(6);
    insertAtBeginning(n5, l);
    NODE n6 = createNewNode(5);
    insertAtBeginning(n6, l); 

    hasCycle(l);
    printList(l);
    n2->next = n6;
    hasCycle(l);
    // printList(l);
}
