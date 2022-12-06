#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void print_array(const int *, int);
void read_array(int *, int);
int *merge(int *, int, int *, int);

void main()
{
    int array_1[MAX], size_1, array_2[MAX], size_2, *array_3, size_3;
    printf("Number of elements in the first array: ");
    scanf("%d", &size_1);
    printf("Enter first array elements: ");
    read_array(array_1, size_1);
    printf("Number of elements in the second array: ");
    scanf("%d", &size_2);
    printf("Enter second array elements: ");
    read_array(array_2, size_2);
    array_3 = merge(array_1, size_1, array_2, size_2);
    size_3 = size_1 + size_2;
    printf("Merged array: ");
    print_array(array_3, size_3);
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

int *merge(int *array_1, int size_1, int *array_2, int size_2)
{
    int i = 0, j = 0, k = 0, *array_3 = (int *)malloc(sizeof(int) * (size_1 + size_2));
    while (i < size_1 && j < size_2)
    {
        array_3[k++] = array_1[i++];
        array_3[k++] = array_2[j++];
    }
    while (i < size_1)
        array_3[k++] = array_1[i++];
    while (j < size_2)
        array_3[k++] = array_2[j++];
    return array_3;
}
