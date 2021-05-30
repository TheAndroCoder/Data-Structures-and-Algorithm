/**
 * Add two numbers represented by linkedlist
 * @author TheAndroCoder
 * */

#include "linkedlist.c"

Node* add(Node* head1,Node* head2){
    Node* head=NULL;
    Node* t1=head1;
    Node* t2=head2;
    int carry=0;
    while(t1!=NULL && t2!=NULL){
        int num = t1->data+t2->data+carry;
        carry = num/10;
        num%=10;
        head=push(head,num);
        t1=t1->next;
        t2=t2->next;
    }
    while(t1!=NULL){
        int num = t1->data+carry;
        carry = num/10;
        num%=10;
        head=push(head,num);
        t1=t1->next;
    }
    while(t2!=NULL){
        int num = t2->data+carry;
        carry = num/10;
        num%=10;
        head=push(head,num);
        t2=t2->next;
    }
    return head;
}

int main(){
    Node* head1=NULL;
    Node* head2=NULL;

    head1=push(head1,5);
    head1=push(head1,6);
    head1=push(head1,3);

    head2=push(head2,8);
    head2=push(head2,4);
    head2=push(head2,2);
    head2=push(head2,1);

    Node* head=add(head1,head2);

    printList(head);
}