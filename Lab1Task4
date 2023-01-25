#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("-------------------------Welcome-------------------------\n");
    printf("What do you want the initial size of the array to be? : ");

    int size, i=0;
    char temp[20];
    scanf("\n%d", &size);
    
    char (*arr)[20]=calloc(size, sizeof(char[20]));
    
    for(i=0; i<size; i++){
        printf("Please enter string at position %d : ", i+1);
        scanf("\n%s", arr[i]);
    }

    // int size;
    // scanf("%d", &size);

    // char **arr;
    // arr = malloc(size * sizeof(char*));
    // for (int i = 0; i < size; i++)
    // {
    //     arr[i] = malloc((20) * sizeof(char));
    // }
    // for(int i=0;i<size;i++){
    //     printf("Please enter string at position %d : ", i+1);
    //     scanf("%s", arr[i]);
    // }
    // for(int i=0;i<size;i++){
    //     printf("%s", arr[i]);
    //     printf("\n");
    // }
    int con = 1;
    while(con){
        printf("\nMenu : \n (a) Add a string to the end of the array,\n(b) Add a string to the beginning of the array,\n(c) Delete the element at index ‘x’ (taken as input) of the array,\n(d) Display the length of the array,\n(e) Display all the elements of the array in sequence,\n(f) Exit \n");
        
        char c;
        scanf("\n%c", &c);
        if(c=='a'){
            size++;
            arr=realloc(arr, (size+1)*sizeof(char[20]));
            printf("Please enter string to be added : ");
            scanf("\n%s", &arr[size-1]);
        }
        if(c=='b'){
            size++;
            arr=realloc(arr, (size+1)*sizeof(char[20]));
            for(int i=size-1;i>1;i--){
                strcpy(arr[i-1], arr[i-2]);
            }
            printf("Please enter string to be added : ");
            scanf("\n%s", &arr[0]);
        }
        if(c=='c'){
            printf("Enter the index of the element you want to delete : ");
            int ind;
            scanf("%d", &ind);
            if(ind>size-1){
                printf("Index out of bounds.\n");
            }
            else{
                for(int i=ind-1;i<size;i++){
                    strcpy(arr[i], arr[i+1]);
                }
                arr = realloc(arr, (size-1)*sizeof(char[20]));
                size--;
            }
        }
        if(c=='d'){
            printf("Size of array = %d", size);
        }
        if(c=='e'){
            for(int i=0;i<size;i++){
                printf("%s\n", arr[i]);
            }
        }
        if(c=='f'){
            con=0;
        }
    }
    free(*arr);
}






    // char *str_array[size];
    // char array_i[size];
    // printf("Enter the strings:\n");
    // for(i=0;i<size;i++)
    // {
    //     scanf("%s", array_i);
    //     str_array[i]= (char*)malloc(strlen(array_i)*sizeof(char));
    //     strcpy(str_array[i],array_i);
    // }

    // printf("Your strings were: \n");
    // for(i=0;i<size;i++)
    // {
    //     printf("%s\n", str_array[I]);
    // }
