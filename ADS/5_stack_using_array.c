#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void push(int);
int pop();
int stack_is_empty();
int peek();
void print();

int STACK[MAX];
int TOP = -1;

void main()
{
    int element, option;
    while (1)
    {
        printf("STACK: ");
        print();
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            printf("Popped %d from stack.\n", element);
            break;
        case 3:
            element = peek();
            printf("Element at peek is %d.\n", element);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Option");
            break;
        }
    }
}

void push(int element)
{
    if (TOP < MAX)
        STACK[++TOP] = element;
    else
        printf("STACK OVERFLOW\n");
}

int pop()
{
    if (TOP > -1)
        return STACK[TOP--];
    else
        printf("STACK UNDERFLOW\n");
}

int stack_is_empty()
{
    return TOP == -1;
}

int peek()
{
    return stack_is_empty() ? -1 : STACK[TOP];
}

void print()
{
    int i;
    for (i = 0; i <= TOP; i++)
        printf("%d ", STACK[i]);
    printf("\n");
}
