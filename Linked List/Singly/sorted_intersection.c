/**
 * Intersection of two Sorted LinkedList
 * @author TheAndroCoder
 * */

#include "linkedlist.c"

Node* getIntersection(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    Node* head=NULL;
    while(t1!=NULL && t2!=NULL){
        if(t1->data==t2->data){
            //printf("Pushing %d\n",t1->data);
            head=push(head,t1->data);
            t1=t1->next;
            t2=t2->next;
        }else if(t1->data<t2->data){
            t1=t1->next;
        }else if(t1->data>t2->data){
            t2=t2->next;
        }
    }
    return head;
}

int main(){
    Node* head1=NULL;
    Node* head2=NULL;

    head1=push(head1,2);
    head1=push(head1,3);
    head1=push(head1,4);
    head1=push(head1,5);

    head2=push(head2,2);
    //head2=push(head2,3);
    head2=push(head2,4);
    head2=push(head2,5);

    Node* head = getIntersection(head1,head2);
    //printList(head);
    head=reverse(head);
    printList(head);
    printReverse(head);
}