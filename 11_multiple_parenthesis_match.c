#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char element)
{
    if (isfull(ptr))
    {
        printf("stack overflow \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}
char pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack underflow\n");
    }
    else
    {
        char c;
        c = ptr->arr[ptr->top];
        ptr->top--;
        return c;
    }
}
char stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
char stackbottum(struct stack *ptr)
{
    return ptr->arr[0];
}
int match(char c1, char c2)
{

    if (c1 == '(' && c2 == ')')

    {
        return 1;
    }
    if (c1 == '[' && c2 == ']')

    {
        return 1;
    }
    if (c1 == '{' && c2 == '}')

    {
        return 1;
    }
    return 0;
}
int parenthesismatch(char *c, int size)
{
    struct stack *p;
    p->size = size;
    p->top = -1;
    p->arr = (char *)malloc(p->size * sizeof(char));
    char popc;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == '(' || c[i] == '[' || c[i] == '{')
        {
            push(p, c[i]);
        }
        else if (c[i] == ')' || c[i] == ']' || c[i] == '}')
        {
            if (isempty(p))
            {
                return 0;
            }
            else
            {
                popc = pop(p);
                if (!match(popc, c[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (isempty(p))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *a = "{[(])}";
    int size = sizeof(a);
    if (parenthesismatch(a, size))
    {
        printf("match\n");
    }
    else
    {
        printf("no match\n");
    }
}
