#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
typedef struct student
{
    long long int ID;
    char name[30];
} student;

typedef struct Node{
    struct Node* next;
    student element;
} Node;

typedef struct List{
    Node* head;
    int count;
}List;

void AddToList(List* l, Node* n){
    if(l->count==0){
        l->head=n;
        l->count++;
        n->next=NULL;
    }
    else{
        Node* temp = l->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        n->next=NULL;
        l->count++;
    }
}

void printList(List* l){
    Node* temp = l->head;
    if(l->count==0){
        printf("[HEAD] -> [NULL]\n");
        return;
    }
    printf("[HEAD] ");
    while(temp && temp->next!=NULL){
        printf("-> %lld , %s ", temp->element.ID, temp->element.name);
        temp=temp->next;
    }
    printf("-> [NULL]\n");
}

long long int ModSize(int size, student* s){
    return (s->ID)%size;
}

long long int ModPowerOfTwoJustLessThanSize(int size, student* s){
    float logval = log2f(size);
    int powerOfTwo = pow(2, logval);
    return (s->ID)%powerOfTwo;
}

bool isPrime(int X)
{
    for (int i = 2; i * i <= X; i++)
            return false;
    return true;
}

long long int ModPrimeJustLessThanSize(int size, student *s){
    int pr;
    for (int j = s->ID - 1;; j--) {
        if (isPrime(j)) {
            pr=j;
            break;
        }
    }
    return (s->ID)%pr;
}

int mulHash(int size, student* s)
{
    double A = 0.6180339887;
    double frac = s->ID * A - (int)(s->ID * A);
    return (int)(size * frac);
}

long long int ModPrimeJustLessThanSizev2(int size, student* s){
    int pr;
    for (int j = ceil(0.9*s->ID) - 1;; j--) {
        if (isPrime(j)) {
            pr=j;
            break;
        }
    }
    return (s->ID)%pr;
}

long long int IDmulPrimeModSize(int size, student* s){
    int pr;
    for (int j = s->ID - 1;; j--) {
        if (isPrime(j)) {
            pr=j;
            break;
        }
    }
    return (s->ID*pr)%size;
}

int main(){
    FILE *fptr = fopen("t1_data.txt", "r+");
    int size;
    fscanf(fptr, "%d ", &size);
    List* hashTable[2*size];
    for(int i=0;i<2*size;i++){
        hashTable[i] = malloc(sizeof(List));
    }
    for(int i=0;i<size;i++){
        long long int id;
        char arr[30];
        fscanf(fptr, "%lld,%[^\n]", &id, arr);
        printf("%lld,%s", id, arr);
        student* new = malloc(sizeof(student));
        new->ID=id;
        strcpy(new->name, arr);
        long long int index = ModSize(size, new);
        Node* nstr = malloc(sizeof(Node));
        nstr->element=*(new);
        nstr->next=NULL;
        AddToList(hashTable[index], nstr);
    }

    for(int i=0;i<size;i++){
        printList(hashTable[i]);
    }

    for(int i=0;i<2*size;i++){
        free(hashTable[i]);
    }

}