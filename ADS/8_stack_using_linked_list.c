#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

struct node *create_node(int);
void push(int);
int pop();
int peek();
void print();
int stack_is_empty();

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

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(int element)
{
    struct node *new_node = create_node(element);
    new_node->next = top;
    top = new_node;
}

int stack_is_empty()
{
    return top == NULL;
}

int pop()
{
    int data;
    struct node *deleted_node = top;
    if (stack_is_empty())
    {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    top = top->next;
    data = deleted_node->data;
    free(deleted_node);
    return data;
}

int peek()
{
    if (top == NULL)
        return -1;
    return top->data;
}

void print()
{
    struct node *current_node = top;
    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}