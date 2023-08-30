#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        printf("stack underflowpop\n");
        return -1;
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
int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else
        return 0;
}
int isoperater(char c)
{
    if (c == '+' || c == '/' || c == '*' || c == '-')
    {
        return 1;
    }
    else
        return 0;
}
char *intopostfix(char *c, int size)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int i = 0;
    int j = 0;
    char *postfix = (char *)malloc((strlen(c) + 1) * sizeof(char));
    while (c[i] != '\0')
    {
        if (!isoperater(c[i]))
        {
            postfix[j] = c[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(c[i]) > precedence(stacktop(s)))
            {
                push(s, c[i]);
                printf("pushed %c\n", c[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s);
                printf("popped %c\n", postfix[j]);
                j++;
            }
        }
    }
    while (!isempty(s))
    {
        postfix[j] = pop(s);
        printf("popped in 2 %c\n", postfix[j]);
        j++;
    }
    // printf("hi\n");
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *ch = "x-y/z-k*d";
    int size = sizeof(ch);
    printf("hi\n");
    printf("%s", intopostfix(ch, size));
    return 0;
}

