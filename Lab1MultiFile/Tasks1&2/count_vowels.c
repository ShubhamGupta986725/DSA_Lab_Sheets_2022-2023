#include "count.h"
int count(char* string)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        char character = tolower(string[i]);
        if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u')
        {
            count++;
        }
    }
    return count;
}
