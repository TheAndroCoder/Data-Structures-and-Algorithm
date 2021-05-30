/**
 * Doubly linkedlist utility functions
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* push(Node* head,int value){
    if(head==NULL){
        head=(Node*)malloc(sizeof(Node));
        head->data=value;
        head->next=NULL;
        head->prev=NULL;
        return head;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=value;
    new->next=NULL;
    new->prev=temp;
    temp->next=new;
    return head;

}
// fix this : TODO
void triplets(Node* head,int x){
    Node* first=head->next;
    Node* last=head;
    while(last->next!=NULL)last=last->next;
    

    Node* fix=head;
    while(fix->next!=NULL && fix->next->next!=NULL){
        // fix this node and use two pointer approach on other two
        int fixed_data = fix->data;
        first=fix->next;
        last=head;
        while(last->next!=NULL)last=last->next;
        int find= x-fixed_data;
        int found=0;
        while(first!=last){
            if(first->data+last->data==find){
                found=1;
                printf("Found\n");
                break;
            }else if(first->data+last->data>find){
                last=last->prev;
            }else{
                first=first->next;
            }
        }
        if(found){
            return;
        }
        fix=fix->next;
    }
    printf("Not found\n");

}
Node* reverse(Node* head){
    Node* prev=head->prev;
    Node* curr=head;
    Node* next=head->next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
    }
    return prev;
}
void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
// int main(){
//     Node* head=NULL;
//     head=push(head,3);
//     head=push(head,5);
//     head=push(head,10);
//     head=push(head,20);
//     head=push(head,25);
//     //head=reverse(head);
//     triplets(head,50);
//     printList(head);
//     return 0;
// }