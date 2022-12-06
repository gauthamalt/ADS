#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

struct node *create_node(int);
void enqueue(int);
int dequeue();
int queue_is_empty();
int peek();
void print();

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

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(int element)
{
    struct node *new_node = create_node(element);
    if (front != NULL)
        rear->next = new_node;
    else
        front = new_node;
    rear = new_node;
    rear->next = front;
}

int queue_is_empty()
{
    return front == NULL;
}

int dequeue()
{
    if (queue_is_empty())
    {
        printf("QUEUE UNDERFLOW\n");
        return -1;
    }
    struct node *deleted_node = front;
    int data = deleted_node->data;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    free(deleted_node);
    return data;
}

int peek()
{
    if (queue_is_empty())
        return -1;
    return front->data;
}

void print()
{
    struct node *current_node = front;
    if (!queue_is_empty())
        do
        {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        } while (current_node != front);
    printf("\n");
}