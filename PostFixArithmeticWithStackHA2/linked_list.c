#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


STACK createNewList(){
    STACK myList;
    myList = (STACK) malloc(sizeof(struct Stack));
    myList->count=0;
    myList->head=NULL;
    return myList;
}

NODE createNewNode(int e){
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct Node));
    myNode->val=e;
    myNode->next=NULL;
    return myNode;
}

void insertNodeIntoList(NODE node, STACK list){
    if(list->count==0){
        list->head=node;
        node->next=NULL;
        list->count++;
    }
    else{
        node->next=list->head;
        list->head=node;
        list->count++;
    }
}

void removeFirstNode(STACK l){
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

void insertNodeAtEnd(NODE node, STACK list){
    if(list->count==0){
        insertNodeIntoList(node, list);
    }
    else{
        NODE temp = list->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node;
        node->next=NULL;
        list->count++;
    }
}