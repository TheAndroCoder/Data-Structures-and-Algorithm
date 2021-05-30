/**
 * Reverse in groups of K
 * @author TheAndroCoder
 * */

#include "linkedlist.c"

Node* k_reverse(Node* head,int k){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL)head->next=k_reverse(next,k);

    return prev;
}
int main(){
    Node* head=NULL;
    head=push(head,2);
    head=push(head,3);
    head=push(head,4);
    head=push(head,5);
    head=push(head,6);
    head=push(head,7);
    head=push(head,8);

    int k=3;
    head=k_reverse(head,k);
    printList(head);
}