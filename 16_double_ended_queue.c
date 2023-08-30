#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *f = NULL;
struct Node *r = NULL;
void linkedlistprint(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
void enqueueR(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("queue full\n");
    }
    else
    {
        n->data = data;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
void enqueueF(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("queue full\n");
    }
    else
    {
        n->data = data;
        n->next = f;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            f = n;
        }
    }
}
void dequeueF()
{
    if (f == NULL)
    {
        printf("queue empty\n");
    }
    else
    {
        struct Node *q = f;

        f = f->next;
        printf("dequeued %d\n", q->data);
        free(q);
    }
}
void dequeueR()
{
    if (r == NULL)
    {
        printf("queue empty\n");
    }
    else
    {
        struct Node *p1 = f;
        struct Node *p2 = f->next;
        while (p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p2->next;
        r = p1;
        printf("dequeued %d\n", p2->data);
        free(p2);
    }
}
int main()
{
    enqueueR(1);
    enqueueR(2);
    enqueueR(3);
    enqueueR(4);
    enqueueF(0);
    enqueueF(-1);
    dequeueF();
    dequeueR();

    // enqueue(1);
    // dequeueR();
    linkedlistprint(f);
}
