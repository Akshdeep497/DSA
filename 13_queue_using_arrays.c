#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isempty(struct queue *p)
{
    if (p->f == p->r)
    {
        return 1;
    }
    return 0;
}
int isfull(struct queue *p)
{
    if (p->r == p->size - 1)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *p, int data)
{
    if (isfull(p))
    {
        printf("queue full\n");
    }
    else
    {
        p->r++;
        p->arr[p->r] = data;
        printf("enqueued %d\n", p->arr[p->r]);
    }
}
void dequeue(struct queue *p)
{
    if (isempty(p))
    {
        printf("queue empty\n");
    }
    else
    {
        p->f++;
        printf("dequeued %d\n", p->arr[p->f]);
    }
}
int main()
{
    struct queue *q;
    q->size = 5;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    dequeue(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    dequeue(q);
    enqueue(q, 6);
}
