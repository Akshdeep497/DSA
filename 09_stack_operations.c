#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
int isfull(struct stack *top)
{
    struct stack *p = malloc(sizeof(struct stack));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct stack *push(struct stack *top, int element)
{
    if (isfull(top))
    {
        printf("\nstack overflow\n");
    }
    else
    {
        struct stack *p = (struct stack *)malloc(sizeof(struct stack));
        p->data = element;
        p->next = top;
        top = p;
        return top;
    }
}
struct stack *push2(struct stack *tp, int element)
{
    if (isfull(tp))
    {
        printf("\nstack overflow\n");
    }
    else
    {
        struct stack *p = (struct stack *)malloc(sizeof(struct stack));
        p->data = element;
        p->next = tp;
        top = p;
        return top;
    }
}
struct stack *pop1(struct stack *top)
{
    if (isempty(top))
    {
        printf("\nstackunderflow");
    }
    struct stack *p = top;
    int element = p->data;
    top = p->next;
    free(p);
    return top;
}
int pop2(struct stack *tp)
{
    if (isempty(top))
    {
        printf("\nstackunderflow");
        return 1;
    }
    struct stack *p = tp;
    top = (tp)->next;
    int a = p->data;
    free(p);
    return a;
}
int pop3(struct stack **top)
{
    if (isempty(*top))
    {
        printf("\nstackunderflow");
        return 1;
    }
    struct stack *p = *top;
    *top = p->next;
    int a = p->data;
    free(p);
    return a;
}
void print(struct stack *top)
{
    while (top != NULL)
    {
        printf("\n%d", top->data);
        top = top->next;
    }
}
int peek(int pos)
{
    struct stack *p = top;
    if (p == NULL)
    {
        printf("\n khali h stack");
    }

    for (int i = 1; (i <= pos - 1 && p != NULL); i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        printf("\n%d", p->data);
    }
    else
    {
        return 0;
    }
}
void stacktop()
{
    printf("\n%d", top->data);
}
void stackbottum()
{
    struct stack *ptr = top;
    if (ptr == NULL)
    {
        printf("\n stack underflow hogya bhai");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("\n%d", ptr->data);
    }
}
int main()
{

    top = push(top, 2);
    top = push(top, 8);
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 4);
    push2(top, 7);
    // top=pop1(top);
    // printf("\npopped %d ", pop2(top));
    // printf("\npopped %d ", pop3(&top));

    // peek(2);
    stacktop();
    stackbottum();
    pop2(top);
    pop2(top);
    pop2(top);
    pop2(top);
    pop2(top);
    pop2(top);
    // pop2(top);
    stackbottum();
    peek(1);

    // print(top);

    return 0;
}
