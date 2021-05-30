/**
 * Swap nodes without swapping data
 * @author TheAndroCoder
 * */

#include "linkedlist.c"

Node* swapNode(Node* head,int x,int y){
    Node* prevX=NULL;
    Node* prevY=NULL;
    Node* X=head;
    Node* Y=head;

    Node* temp=head;
    while(temp!=NULL && temp->data!=x){
        prevX=temp;
        temp=temp->next;
    }
    X=temp;
    
    if(X==NULL){
        printf("%d not found in list\n",x);
        return head;
    }
    temp=head;
    while(temp!=NULL && temp->data!=y){
        prevY=temp;
        temp=temp->next;
    }
    Y=temp;
    if(head->data==x){
        Node* p=X->next;
        X->next=Y->next;
        prevY->next=X;
        Y->next=p;
        return Y;
    }
    if(head->data==y){
        Node* p=X->next;
        X->next=Y->next;
        prevX->next=Y;
        Y->next=p;
        return X;
    }
    if(Y==NULL){
        printf("%d not found in list\n",y);
        return head;
    }
    
    X->next=Y->next;
    Y->next=X;
    prevX->next=Y;
    
    return head;
}

int main(){
    Node* head=NULL;
    head=push(head,5);
    head=push(head,10);
    head=push(head,15);
    head=push(head,20);
    head=swapNode(head,5,20);
    printList(head);
    return 0;
}