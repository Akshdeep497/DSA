#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int * arr;
    
};
int isempty(struct queue * q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct queue* q){
    if(q->r==q->size-1){
        return 1;

    }
    else
        return 0;
    
}
void enqueue(struct queue * q,int data){
    if(isfull(q)){
        printf("queue full\n");

        
    }
    else{
        q->r++;
        q->arr[q->r]=data;
    }
}
int dequeue(struct queue* q){
    if(isempty(q)){
        printf("queue empty\n");
    }
    else{
        q->f++;
        int a=q->arr[q->f];
        return a;
    }
}
int main()
{   struct queue * q;
    q->size=400;
    q->f=q->r=-0;
    q->arr=(int*)malloc(q->size*sizeof(int));
    int visited[7]={0,0,0,0,0,0,0};
    int i=1;
     int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("visited %d\n",i);
    visited[i]=1;
    enqueue(q,i);
    while(!isempty(q)){
        int node=dequeue(q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1&&visited[j]==0){
                visited[j]=1;
                enqueue(q,j);
                printf(" %d",j);

            }
        }
    }


    return 0;
}
