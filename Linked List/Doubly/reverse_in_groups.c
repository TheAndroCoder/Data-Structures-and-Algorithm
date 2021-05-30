/**
 * Reverse in grousp of K
 * @author TheAndroCoder
 * */

#include "dlinkedlist.c"

// TODO : This method doesnot work as this is not the correct algorithm for reversing DLL
Node* reverse_k(Node* head,int k){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    int count=0;
    if(curr->next==NULL && curr==NULL)return NULL;
    while(curr->next!=NULL && count++<k){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
    }
    prev=reverse_k(curr,k);
    printf("prev : %d, curr: %d, next: %d\n",prev->data,curr->data,next->data);
    return prev;
}

int main(){
    Node* head=NULL;
    head=push(head,3);
    head=push(head,12);
    head=push(head,45);
    head=push(head,32);
    head=push(head,89);
    head=push(head,66);
    head=push(head,90);
    head=push(head,55);
    int k=3;
    head=reverse_k(head,k);
}