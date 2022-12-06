#include <stdio.h>
#define MAX 10

int swap(int *, int *);
void sort(int *, int);
void print_array(const int *, int);
void read_array(int *, int);

void main()
{
    int array[MAX], size, i;
    printf("Number of elements in the array: ");
    scanf("%d", &size);
    printf("Enter elements: ");
    read_array(array, size);
    printf("Array before sorting: ");
    print_array(array, size);
    sort(array, size);
    printf("Array after sorting: ");
    print_array(array, size);
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

int swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void sort(int *array, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size - i + 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}
