#include <stdio.h>

// Function to take input an array A and return an array B after performing counting sort on it with array C
int* counting_sort(char* A, char* B, int k, int n) 
{
    // Initialize array C with all 0s
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }

    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        C[A[j]]++;
    }
    
    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
    return B;
}

// Driver code to test the above function

int main(){
    int size;
    printf("Enter size of string : ");
    scanf("%d", &size);
    printf("Enter the string : ");
    char arr[size+1];
    scanf("%s", arr);

    /*    int k = A[0];
    for (int i = 1; i < n; i++) 
    {
        if (A[i] > k) 
        {
            k = A[i];
        }
    }*/
    char sort[size+1];
    counting_sort(arr, sort, 'z', size);
    printf("%s", sort);
}