/**
 * Print middle element
 * @author TheAndroCoder
 * */

#include "linkedlist.c"

void printMiddle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("Middle Element : %d\n",slow->data);
}
int main(){
    Node *head=NULL;
    head=push(head,3);
    head=push(head,5);
    head=push(head,10);
    head=push(head,15);
    head=push(head,25);
    
    printMiddle(head);
    return 0;
}