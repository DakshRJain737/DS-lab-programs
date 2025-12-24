#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void main()
{
    char infix[50], postfix[50], c;
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    push('#');

    while ((c = infix[i++]) != '\0')
    {
        if (c == '(')
            push(c);
        else if (isalnum(c))
            postfix[j++] = c;
        else if (c == ')')
        {
            while ((c = stack[top]) != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (stack[top] != '#')
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("\nPostfix Exp: %s", postfix);
    return;
}

// A+B*(C^D-E)^(F+G*H)-I
