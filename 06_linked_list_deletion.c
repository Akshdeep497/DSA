#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node * next;
};
void print(struct Node* head){
    struct Node *ptr=head;
    int i=0;
    do{
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct Node * insertatfirst(struct Node* head,int element){
    struct Node*ptr=malloc(sizeof(struct Node));
    struct Node* p=head->next;
    ptr->data=element;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;

    return head;


}
struct Node * insertatindex(struct Node * head,int index,int data){
    struct Node *ptr=malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node * insertatlast(struct Node * head,int data){
    struct Node *ptr=malloc(sizeof(struct Node));
    struct Node *p=head;
    do{
        p=p->next;
    }while(p!=head);
    ptr->data=data;
    ptr->next=head;
    p->next=ptr;
    return head;
}
struct Node * insertafternode(struct Node *head,struct Node *prevnode,int data){
    struct Node * ptr=malloc(sizeof(struct Node));
    struct Node *p=prevnode;
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;

}
struct Node * deleteatfirst(struct Node * head){
    struct Node * ptr=head;
    struct Node * p=head;
    do{
        p=p->next;
    }while(p->next!=head);
    p->next=ptr->next;
    head =ptr->next;
    free(ptr);
    return head;
    }
struct Node * deleteatindex(struct Node * head,int index){
    struct Node * ptr1=head;
    struct Node * ptr2=head->next;
    int i=0;
    while(i!=index-1){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        i++;
    }
    ptr1->next=ptr2->next;
    free(ptr2);
    return head;
} 
struct Node * deleteatlast(struct Node * head){
    struct Node * ptr1=head;
    struct Node * ptr2=head->next;
    do{
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }while(ptr2->next!=head);
    ptr1->next=head;
    free(ptr2);
    return head;
}
struct Node * deleteatlast2(struct Node* head){
    struct Node * ptr=head;
    struct Node * q=head->next;
    while(q->next!=head){
       ptr=ptr->next;
        q=q->next;
    }
    ptr->next=head;
    free(q);
    return head;

}
struct Node* deletebyvalue(struct Node * head,int value){
struct Node * ptr1=head;
struct Node*  ptr2=head->next;
while(ptr2->data!=value){
    ptr1=ptr1->next;
    ptr2=ptr2->next;

}
ptr1->next=ptr2->next;
free(ptr2);
return head;

}


int main()
{
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
fourth->next=head;
print(head);
//head=insertatfirst(head,6);
//head=insertatindex(head,1,5);
//head=insertatlast(head,8);
//head=insertafternode(head,second,5);
//head=deleteatfirst(head);
//head=deleteatindex(head,2);
//head=deleteatlast(head);
head=deletebyvalue(head,2);
print(head);

    return 0;
}
