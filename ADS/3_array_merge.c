#include <stdio.h>
#define MAX 20

void print_array(const int *, int);
void read_array(int *, int);
void merge(int *, int *, int *, int);

void main()
{
    int array_1[MAX], size_1, array_2[MAX], size_2;
    printf("Number of elements in the first array: ");
    scanf("%d", &size_1);
    printf("Enter first array elements: ");
    read_array(array_1, size_1);
    printf("Number of elements in the second array: ");
    scanf("%d", &size_2);
    printf("Enter second array elements: ");
    read_array(array_2, size_2);
    merge(array_1, &size_1, array_2, size_2);
    printf("Merged array: ");
    print_array(array_1, size_1);
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

void merge(int *array_1, int *size_1, int *array_2, int size_2)
{
    int i;
    for (i = 0; i < size_2; i++)
        array_1[*size_1 + i] = array_2[i];
    *size_1 += size_2;
}
