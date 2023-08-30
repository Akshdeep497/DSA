#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* insertatfirst(struct Node*head,int data){
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

 struct Node* insertatindex(int index,int data,struct Node * head){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i =0;
    while(i!=index-1){
        p=p->next;
        i++;

    }
    
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

     
 }
 struct Node * insertatend(int data,struct Node *head){
    struct Node * ptr=malloc(sizeof(struct Node));
    struct Node * p=head;
    int i=0;
    while(p->next!=NULL){
        p=p->next;
        
            }
            ptr->data=data;
            ptr->next=NULL;
            p->next=ptr;
            return head;
 }
void print(struct Node*ptr){
    while(ptr!=NULL){
        printf("\nelement %d",ptr->data);
       ptr= ptr->next;

    }
    
}
struct Node * insertafterNode(struct Node * head,struct Node *prevnode,int data){
    struct Node *ptr=malloc(sizeof(struct Node));
    struct Node *p=prevnode;
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
   third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    
    third->data=3;
    third->next=fourth;


    fourth->data=4;
    fourth->next=NULL;
    print(head);
    head=insertatfirst(head,3);
    print(head);
    head=insertatindex(1,4,head);
    printf("\ncase 2");
    print(head);
    printf("\ncase 3");
    head=insertatend(2,head);
    print(head);
    printf("\ncase 4");
    head=insertafterNode(head,second,5);
    print(head);


    return 0;
}
