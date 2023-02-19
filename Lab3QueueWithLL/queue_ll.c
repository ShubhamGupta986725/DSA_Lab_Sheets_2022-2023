#include "queue_ll.h"


Queue *createQueue(){
    QUEUE q = createNewList();
    return q;
}

bool enqueue(Queue *queue, Element element){
    NODE n = createNewNode(element);
    insertNodeAtEnd(n, queue);
    return true;
}

bool dequeue(Queue *queue){
    if(queue->count==0){
        return false;
    }
    removeFirstNode(queue);
    return true;
}

Element *front(Queue *queue){
    return queue->head;
}

int size(Queue *queue){
    return queue->count;
}

bool isEmpty(Queue *queue){
    if(queue->count==0){
        return true;
    }
    return false;
}

void destroyQueue(Queue *queue){
    free(queue);
}