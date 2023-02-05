#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct student* Student;
struct student{
    char ID[14];
    float cgpa;
};
typedef struct node* NODE;
struct node{
    Student s;
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

NODE createNewNode(char *ID, float cg)
{
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->s->cgpa=cg;
    strcpy(myNode->s->ID,ID);
    myNode->next=NULL;
    return myNode;
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



int main(){
    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    
    Student s = (Student)malloc(10000*sizeof(struct student));
    FILE *fp = fopen("data.txt", "r");
    
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    } else {
        int i = 0;
        while(fscanf(fp, "%[^,],%f\n", s[i].ID, &s[i].cgpa) != EOF) {
            i++;
        }
    }

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Time taken for Dynamic Array = %lf\n", time_taken);
    free(s);





    struct timeval t3, t4;
    double time_taken2;
    gettimeofday(&t3, NULL);
    
    LIST l1 = createNewList();
    
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    } else {
        int i = 0;
        struct student s;
        while(fscanf(fp, "%[^,],%f\n", s.ID, &s.cgpa) != EOF) {
            NODE n = createNewNode(s.ID, s.cgpa);
            insertAtBeginning(n,l1);       
        }
    }

    gettimeofday(&t4, NULL);
    time_taken2 = (t4.tv_sec - t3.tv_sec) * 1e6;
    time_taken2 = (time_taken2 + (t4.tv_usec - t3.tv_usec)) * 1e-6;
    printf("Time taken for Linked List = %lf", time_taken2);

    free(l1);

    fclose(fp);
}