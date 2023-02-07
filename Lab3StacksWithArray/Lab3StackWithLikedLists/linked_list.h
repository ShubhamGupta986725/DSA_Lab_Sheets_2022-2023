typedef struct Element
{
    int int_value;
    float float_value;
} element;

typedef struct Node
{
    element data;
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
NODE createNewNode(element e);
void insertNodeIntoList(NODE node, STACK st);
void removeFirstNode(STACK st);
void insertNodeAtEnd(NODE node, STACK st);