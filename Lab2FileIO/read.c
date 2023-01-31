#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    FILE *fptr;
    fptr = fopen("program.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    fscanf(fptr, "%d", &num);
    printf("Value of n = %d\n", num);
    fclose(fptr);
    return 0;
}
