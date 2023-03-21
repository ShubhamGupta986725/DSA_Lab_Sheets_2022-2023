#include <stdio.h>
#include <stdlib.h>

int *createBloomFilter(int size)
{
    int numIntsRequired = size % (sizeof(int) * 8) == 0 ? size / (sizeof(int) * 8) : size / (sizeof(int) * 8) + 1;
    int *filter = (int *)malloc(numIntsRequired * sizeof(int));
    return filter;
}

void setBit(int *filter, int index)
{
    int i = index / (sizeof(int) * 8); // This is the index of the int containing the bit we want to set
    int j = index % (sizeof(int) * 8); // This is the index of the bit we want to set in the int
    filter[i] = filter[i] | (1 << j); // Set the bit
}
int checkBit(int *filter, int index) // Returns 1 if the bit is set, 0 otherwise
{
    int i = index / (sizeof(int) * 8); // This is the index of the int containing the bit we want to set
    int j = index % (sizeof(int) * 8); // This is the index of the bit we want to set in the int
    int bit = (filter[i] >> j) & 1; // Get the bit
    return bit;
}

int mulHash(int key)
{
    double A = 0.6180339887;
    double frac = key*A - (int)(key*A);
    return (int)(key*frac);
}

void h1(int k, int* filter){
    int index = k%256;
    setBit(filter, index);
}
void h2(int k, int* filter){
    int index = mulHash(k);
    setBit(filter, index);
}
void h3(int k, int* filter){
    int index = k%43;
    setBit(filter, index);
}
void h4(int k, int* filter){
    int index = (k^(k>>3))%256;
    setBit(filter, index);
}
void h5(int k, int* filter){
    int index = 255-(k%197);
    setBit(filter, index);
}

void insert(int k, int* f){
    h1(k,f);
    h2(k,f);
    h3(k,f);
    h4(k,f);
    h5(k,f);
}

void lookUp(int k, int* f){
    int ind1 = k%256;
    int ind2 = mulHash(k);
    int ind3 = k%43;
    int ind4 = (k^(k>>3))%256;
    int ind5 = 255-(k%197);
    if(ind1 && ind2 && ind3 && ind4 && ind5){
        printf("Present in Bloom Filter (Maybe)\n");
    }
    else{
        printf("Not in Bloom Filter\n");
    }
}

int main(){
    int* bf = createBloomFilter(256);
    FILE *fptr = fopen("bloom_numbers.txt", "r+");
    for(int i=0;i<50;i++){
        int k;
        fscanf(fptr, "%d ", &k);
        insert(k, bf);
    }
    fclose (fptr);
    FILE *fptr2 = fopen("bloom_numbers.txt", "r+");
    for(int i=0;i<100;i++){
        int k;
        fscanf(fptr2, "%d ", &k);
        lookUp(k, bf);
    }
    fclose (fptr2);
}