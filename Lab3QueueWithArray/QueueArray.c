#include "Queue.h"
#include "heap_usage.h"
#define ARRAY_SIZE 100

// rear = (front + size - 1) % ARRAY_SIZE

typedef struct Queue{
    int rear;
    int front;
    Element arr[ARRAY_SIZE];
    int size; 
} Queue;


Queue *createQueue(){
    Queue* q = myalloc(sizeof(Queue));
    q->rear=0;
    q->front=0;
    q->size=0;
    return q;
}

bool enqueue(Queue *queue, Element element){
    if(queue->size==ARRAY_SIZE){
        return false;
    }
    else{
        queue->arr[queue->rear]=element;
        queue->rear++;
        queue->size++;
        return true;
    }
}
bool dequeue(Queue *queue){
    if(queue->size==0){
        return false;
    }
    else{
        queue->front++;
        queue->size--;
        return true;
    }
}
Element *front(Queue *queue){
    if(queue->size==0){
        return NULL;
    }
    else{
        return &(queue->arr[queue->front]);
    }
}
int size(Queue *queue){
    return queue->size;
}
bool isEmpty(Queue *queue){
    if(queue->size==0){
        return true;
    }
    else{
        return false;
    }
}
void destroyQueue(Queue *queue){
    myfree(queue);
}