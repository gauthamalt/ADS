#include <stdio.h>
#define MAX 10

int search(int *, int, int);
void read_array(int *, int);

void main()
{
    int array[MAX], element, position, size, i;
    printf("Number of elements in the array: ");
    scanf("%d", &size);
    printf("Enter elements: ");
    read_array(array, size);
    printf("Enter element to search: ");
    scanf("%d", &element);
    position = search(array, size, element);
    if (position == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", position);
}

void read_array(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

int search(int *array, int size, int element)
{
    int i;
    for (i = 0; i < size; i++)
        if (array[i] == element)
            return i + 1;
    return -1;
}