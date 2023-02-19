#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdbool.h>
#include <stdio.h>
#include "element.h"

struct node
{
    Element data;
    struct node *next;
};
typedef struct node node;
typedef node * NODE;

struct Queue
{
    int count;
    NODE head;
    NODE tail; // Not required for stack. Required for Queue
};
typedef struct Queue Queue;
typedef Queue * QUEUE;

QUEUE createNewList();
// This function allocates memory for a new list and returns a pointer to it.
// The list is empty and the count is set to 0.

NODE createNewNode(Element data);
// This function allocates memory for a new node and returns a pointer to it.
// The next pointer is set to NULL and the data is set to the value passed in.

void insertNodeIntoList(NODE node, QUEUE list);
// This function inserts a node at the beginning of the list.

void removeFirstNode(QUEUE list);
// This function removes the first node from the list.

void insertNodeAtEnd(NODE node, QUEUE list);
// This function inserts a node at the end of the list.

void destroyList(QUEUE list);
#endif