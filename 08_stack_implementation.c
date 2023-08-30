#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 void print (struct stack * ptr){
    for(int i=0;i<=ptr->top;i++){
        printf("\n%d",ptr->arr[i]);
    }
 }
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int stacktop(struct stack *ptr){
    return ptr->arr[ptr->top];
}
int stackbottum(struct stack *ptr){
    int index;
    index=ptr->top-ptr->size+1;
    return ptr->arr[index];
}
int stackbottum2(struct stack *ptr){
    
    return ptr->arr[0];
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *ptr ,int pos){
    int index=ptr->top-pos+1;
    printf("\n%d",ptr->arr[index]);
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);
    push(sp,7);
    push(sp,8);
    push(sp,9);
    push(sp,10);
    for(int i=sp->size;i>=1;i--){
        peek(sp,i);
    }
    printf("\nstack top %d",stacktop(sp));
    printf("\n stack bottum %d",stackbottum2(sp));
   
    
 
    return 0;
}


