#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int min(int a, int b){
    return a<b?a:b;
}
int main()
{
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    srand(time(NULL));
    int r = rand() % abs((b - a + 1)) + min(a,b);
    printf("Random number between %d and %d is %d\n", a, b, r);
    return 0;
}