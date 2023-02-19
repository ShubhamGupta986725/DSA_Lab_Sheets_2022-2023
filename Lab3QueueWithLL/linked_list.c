#include "linked_list.h"

QUEUE createNewList(){
    QUEUE l = malloc(sizeof(struct Queue));
    l->count=0;
    l->head=NULL;
    l->tail=NULL;
    return l;
}

NODE createNewNode(Element data){
    NODE new = malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
}

void insertNodeIntoList(NODE node, QUEUE list){
    if(list->count==0){
        node->next=list->head;
        list->head=node;
        list->tail=node;
        list->count++;
    }
    else{
        node->next=list->head;
        list->head=node;
        list->count++;
    }
}

void removeFirstNode(QUEUE list){
    if(list->count==0){
        return;
    }
    else{
        NODE temp=list->head;
        list->head=temp->next;
        free(temp);
        list->count--;
    }
}

void insertNodeAtEnd(NODE node, QUEUE list){
    if(list->count==0){
        insertNodeIntoList(node,list);
    }
    else{
        list->tail->next=node;
        list->count++;
    }
}

void destroyList(QUEUE list){

    free(list);
    // NODE temp = list->head;
    // NODE temp2 = list->head->next;
    
    // while(temp2->next!=NULL){
    //     free(temp);
    //     temp=temp2;
    //     temp2=temp2->next;
    // }
    // free(temp2);
    // free(list);
}