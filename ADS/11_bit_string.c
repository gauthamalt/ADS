#include <stdio.h>
#define SIZE 10

int main()
{
    int array[SIZE], count, i;
    char bit_string[SIZE + 1];
    printf("Enter array count:");
    scanf("%d", &count);
    printf("Enter elements: ");
    for (i = 0; i < count; i++)
        scanf("%d", &array[i]);
    printf("Enter bitstring: ");
    scanf(" %[^\n]", bit_string);
    for (i = 0; i < count; i++)
        if (bit_string[i] == '1')
            printf("%d ", array[i]);
    return 0;
}