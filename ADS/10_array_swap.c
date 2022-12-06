#include <stdio.h>
#define MAX 10

void swap_array(int *, int *, int);
void read_array(int *, int);
void print_array(const int *, int);

void main()
{
    int array_1[MAX], array_2[MAX], size;
    printf("Number of elements in the array: ");
    scanf("%d", &size);
    printf("Enter first array: ");
    read_array(array_1, size);
    printf("Enter second array: ");
    read_array(array_2, size);
    swap_array(array_1, array_2, size);
    printf("After Swap:\n");
    printf("First Array: ");
    print_array(array_1, size);
    printf("Second Array: ");
    print_array(array_2, size);
}

void print_array(const int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void read_array(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

void swap_array(int *array_1, int *array_2, int size)
{
    int temp, i;
    for (i = 0; i < size; i++)
    {
        temp = array_1[i];
        array_1[i] = array_2[i];
        array_2[i] = temp;
    }
}