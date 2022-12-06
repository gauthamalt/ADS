#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int TOP = -1;

void push(char c)
{
    if (TOP < MAX)
        stack[++TOP] = c;
    else
        printf("STACK OVERFLOW\n");
}

char pop()
{
    if (TOP > -1)
        return stack[TOP--];
    else
        printf("STACK UNDERFLOW\n");
}

int precedence(char operator)
{
    switch (operator)
    {
    case '^':
        return 3;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    default:
        return -1;
        break;
    }
}

int is_operand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int stack_is_empty()
{
    return TOP == -1;
}

int peek()
{
    return stack[TOP];
}

/*
Scan the infix expression from left to right.
If the scanned character is an operand, output it.
Else,
If the precedence and associativity of the scanned operator are greater than the precedence and associativity of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), then push it.
‘^’ operator is right associative and other operators like ‘+’,’-‘,’*’ and ‘/’ are left-associative. Check especially for a condition when both,  operator at the top of the stack and the scanned operator are ‘^’. In this condition, the precedence of the scanned operator is higher due to its right associativity. So it will be pushed into the operator stack. In all the other cases when the top of the operator stack is the same as the scanned operator, then pop the operator from the stack because of left associativity due to which the scanned operator has less precedence.
Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
If the scanned character is an ‘(‘, push it to the stack.
If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis.
Repeat steps 2-6 until the infix expression is scanned.
Print the output
Pop and output from the stack until it is not empty.
*/
void convert_to_postfix(char *expression)
{
    char c;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        c = expression[i];
        if (is_operand(c))
        {
            printf("%c", c);
        }
        else if (c == ')')
        {
            c = pop();
            while (c != '(' && !stack_is_empty())
            {
                printf("%c", c);
                c = pop();
            }
        }
        else if (precedence(c) > precedence(peek()) || stack_is_empty() || expression[i] == '(')
        {
            push(c);
        }
        else if (precedence(c) == precedence(peek()) && peek() == '^')
        {
            push(c);
        }

        else
        {
            while (precedence(peek()) >= precedence(c))
            {
                printf("%c", pop());
            }
            push(c);
        }
    }
    while (!stack_is_empty())
    {
        printf("%c", pop());
    }
}

int main()
{
    char expression[100];
    printf("Enter the expression: ");
    scanf("%s", expression);
    convert_to_postfix(expression);
    return 0;
}
