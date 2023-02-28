#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

typedef struct person
{
    int id;
    char name[100];
    int age;
    int height;
    int weight;
} person;

void swap(person Ls[], int i1, int i2){
    person a = Ls[i1];
    person b = Ls[i2];
    Ls[i2] = a;
    Ls[i1] = b;
}

int HoareTwoWay(person Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, lo);
    int pivPos, lt, rt;
    person pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt)
    {
        for (; lt <= hi && Ls[lt].height <= pv.height; lt++);
        for (; Ls[rt].height > pv.height; rt--);
        if (lt < rt)
        {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt].height < pv.height && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(Ls, lo, pivPos);
    return pivPos;
}

int HoareThreeWay(person Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, hi - 1);
    int pivPos, lt, rt, mid;
    person pv;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    pv = Ls[hi - 1];
    while (mid <= rt)
    {
        if (Ls[mid].height < pv.height)
        {
            swap(Ls, lt, mid);
            lt++;
            mid++;
        }
        else if (Ls[mid].height > pv.height)
        {
            swap(Ls, mid, rt);
            rt--;
        }
        else
        {
            mid++;
        }
    }
    swap(Ls, mid, hi - 1);
    return mid;
}

int Lomuto(person Ls[], int lo, int hi)
{
    person piv = Ls[hi];
    int i = lo-1;
    for (int j = lo; j <= hi- 1; j++)
    {
        if (Ls[j].height <= piv.height)
        {
            i++;
            swap(Ls, i, j);
        }
    }
    swap(Ls,i + 1, hi);
    return (i + 1);
}

int main(){

    FILE* ptr;
    ptr=fopen("dat1000.csv", "r");

    person arrHTwW[1000];
    person arrHthW[1000];
    person arrL[1000];
    if(ptr==NULL){
        printf("File couldn't be opened.\n");
        return 0;
    }
    int i=0;
    while(fscanf(ptr, "%d,%[^,],%d,%d,%d\n", &(arrHTwW[i].id), arrHTwW[i].name, &(arrHTwW[i].age), &(arrHTwW[i].height), &(arrHTwW[i].weight))!=-1){
        // printf("%d %s %d %d %d\n", arrHTwW[i].id, arrHTwW[i].name, arrHTwW[i].age, arrHTwW[i].height, arrHTwW[i].weight);
        arrHthW[i].id = arrHTwW[i].id;
        strcpy(arrHthW[i].name, arrHTwW[i].name);
        arrHthW[i].age = arrHTwW[i].age;
        arrHthW[i].height = arrHTwW[i].height;
        arrHthW[i].weight = arrHTwW[i].weight;
        arrL[i].id = arrHTwW[i].id;
        strcpy(arrL[i].name, arrHTwW[i].name);
        arrL[i].age = arrHTwW[i].age;
        arrL[i].height = arrHTwW[i].height;
        arrL[i].weight = arrHTwW[i].weight;
        i++;
    }
    struct timeval t1,t2;
    double time_taken;

    gettimeofday(&t1,NULL);
    HoareTwoWay(arrHTwW, 0, 999, 999);
    gettimeofday(&t2, NULL);

    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("The tasks took %f seconds to execute Hoare Two Way Partitioning.\n", time_taken);


    gettimeofday(&t1,NULL);
    HoareThreeWay(arrHthW, 0, 999, 999);
    gettimeofday(&t2, NULL);

    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("The tasks took %f seconds to execute Hoare Three Way Partitioning.\n", time_taken);


    gettimeofday(&t1,NULL);
    Lomuto(arrL, 0, 999);
    gettimeofday(&t2, NULL);

    time_taken = ((t2.tv_sec) - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("The tasks took %f seconds to execute Lomuto.\n", time_taken);
}