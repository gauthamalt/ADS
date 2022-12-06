#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void enqueue(int);
int dequeue();
int queue_is_empty();
int queue_is_full();
int peek();
void print();

int QUEUE[MAX];
int FRONT = -1, REAR = -1;

void main()
{
    int element, option;
    while (1)
    {
        printf("QUEUE: ");
        print();
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            element = dequeue();
            printf("Popped %d from queue.\n", element);
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

void enqueue(int element)
{
    if (REAR == -1)
        FRONT = 0;
    if (REAR < MAX)
        QUEUE[++REAR] = element;
    else
        printf("QUEUE OVERFLOW\n");
}

int dequeue()
{
    int element;
    if (FRONT > -1)
    {
        element = QUEUE[++FRONT];
        if (FRONT > REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        return element;
    }
    else
        printf("QUEUE UNDERFLOW\n");
}

int queue_is_empty()
{
    return FRONT == -1;
}

int queue_is_full()
{
    return REAR == MAX - 1;
}

int peek()
{
    return queue_is_empty() ? -1 : QUEUE[FRONT];
}

void print()
{
    int i;
    if (queue_is_empty())
    {
        printf("\n");
        return;
    }
    for (i = FRONT; i <= REAR; i++)
        printf("%d ", QUEUE[i]);
    printf("\n");
}
