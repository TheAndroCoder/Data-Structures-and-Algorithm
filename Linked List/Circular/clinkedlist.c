/**
 * Basic utility methods for circular linkdlist
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* push(Node* head,int data){
    if(head==NULL){
        head = (Node*)malloc(sizeof(Node));
        head->data=data;
        head->next=head;
        return head;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;

    }
    Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data=data;
        temp->next=new_node;
        new_node->next=head;
    return head;
}

Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;

    while(next!=head){
        next=curr->next;
        //if(next==head)return head;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    curr->next=prev;
    return prev;
}
Node* exchange_first_last(Node* head){
    Node* first=head;
    Node* last=head;
    if(head->next->next==head)return head->next;
    while(last->next->next!=head){
        last=last->next;
    }
    last->next->next=head->next;
    head->next=last->next;
    last->next=head;
    return head->next;
      
}

void printList(Node* head){
    Node* temp=head;
    do{
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
int main(){
    Node* head=NULL;
    head=push(head,2);
    head=push(head,4);
    head=push(head,10);
    head=push(head,16);
    head=reverse(head);
    head=exchange_first_last(head);
    printList(head);
    return 0;
}