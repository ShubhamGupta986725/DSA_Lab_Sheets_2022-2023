typedef struct Node
{
    int val;
    struct Node* next;
} node;
typedef node* NODE;

typedef struct Stack
{
    int count;
    NODE head;
// NODE tail; // Not required for stack. Required for Queue
} stack;
typedef stack* STACK;


STACK createNewList();
NODE createNewNode(int e);
void insertNodeIntoList(NODE node, STACK st);
void removeFirstNode(STACK st);
void insertNodeAtEnd(NODE node, STACK st);