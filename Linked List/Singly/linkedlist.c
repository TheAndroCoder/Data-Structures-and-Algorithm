/**
 * Basic functions to build singly linkedlist
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* next;
    int data;
}Node;
int size=0;
Node* push(Node* head,int data){
    if(head==NULL){
        head=(Node*)malloc(sizeof(Node));
        head->next=NULL;
        head->data=data;
    }else{
        Node* temp=head;
        while(temp->next!=NULL)temp=temp->next;
        Node* new_node=(Node*)malloc(sizeof(Node));
        new_node->next=NULL;
        new_node->data=data;
        temp->next=new_node;
    }
    size++;
    return head;
}
Node* removePos(Node* head,int pos){
    if(pos<0 || pos>size-1)return head;
    if(pos==0){
        // remove head;
        Node* ret=head->next;
        free(head);
        return ret;
    }else{
        Node* temp=head;
        while(pos--!=1){
            temp=temp->next;
        }
        Node* rem=temp->next;
        free(rem);
        temp->next=temp->next->next;
    }
    size--;
    return head;
}

Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void printReverse(Node* head){
    if(head==NULL)return;
    printReverse(head->next);
    printf("%d\t",head->data);
}
void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
