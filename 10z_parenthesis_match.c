#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
int isEmpty(struct stack *ptr)
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
int isFull(struct stack *ptr)
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
    if (isFull(ptr))
    {
        printf("stackoverflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack underflow\n");
        return 1;
    }
    else
    {
        char c;
        c = ptr->arr[ptr->top];
        ptr->top--;
        return c;
    }
}
void print(struct stack *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%d\n", ptr->arr[i]);
    }
}
int parenthesismatch(char *ch, int len)
{
    struct stack *s;
    s->top = -1;
    s->size = len;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int i;
    for (i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] == '(')
        {
            push(s, ch[i]);
        }
        else if (ch[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                pop(s);
            }
        }
    }
    if (isEmpty(s))
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
    char *ch = "((1*2)";
    int len = strlen(ch);
    if (parenthesismatch(ch, len))
    {
        printf("match\n");
    }
    else
    {
        printf("notmatch\n");
    }

    return 0;
}
