#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
void print (struct Node * head){
    while(head!=NULL){
        
        printf(" %d\n",head->data);
        head=head->next;
    }
    printf("\n");
}
struct Node * deleteatfirst(struct Node * head){
    struct Node * ptr=head;
    head =ptr->next;
    free(ptr);
    return head;

}
struct Node * deleteatindex(struct Node * head,int index){
    struct Node *ptr=head;
    struct Node *q=head->next;
    int i=0;
   for (int i=0;i<index-1;i++){
    ptr=ptr->next;
    q=q->next;
   }
   ptr->next=q->next;
   free(q);
   return head;
}

    
struct Node * deleteatlast(struct Node* head){
    struct Node * ptr=head;
    struct Node * q=head->next;
    while(q->next!=NULL){
       ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    free(q);
    return head;

}
struct Node* deletebyvalue(struct Node* head,int element){
    struct Node * ptr=head;
    struct Node * q=head->next;
    while (q->data!=element&&q->next!=NULL){
        ptr=ptr->next;
        q=q->next;

    }
    ptr->next=q->next;
    free(q);
    return head;
}
int main(){
struct Node * head;
struct Node * second;
struct Node * third;
struct Node * fourth;
head=(struct Node *)malloc(sizeof(struct Node));
second=(struct Node *)malloc(sizeof(struct Node));
third=(struct Node *)malloc(sizeof(struct Node));
fourth=(struct Node *)malloc(sizeof(struct Node));
head->data=1;
head->next=second;
second->data=2;
second->next=third;
third->data=3;
third->next=fourth;
fourth->data=4;
fourth->next=NULL;
print(head);
//head=deleteatfirst(head);
//head=deleteatindex(head,1);
//head=deleteatlast(head);
head=deletebyvalue(head,2);


print (head);

    return 0;
}
