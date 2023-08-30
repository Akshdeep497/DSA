#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isempty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
int isfull(struct queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int data)
{
    if (isfull(q))
    {
        printf("queue full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
        printf("enqueued %d\n", q->arr[q->r]);
    }
}
void dequeue(struct queue *q)
{
    if (isempty(q))
    {
        printf("queue empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        printf("dequeued %d\n", q->arr[q->f]);
    }
}
int main()
{
    struct queue *q;
    q->size = 4;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    dequeue(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    dequeue(q);
    enqueue(q, 4);
}
