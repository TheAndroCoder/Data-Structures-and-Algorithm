/**
 * Insertion sort for singly linkedlist
 * @author TheAndroCoder
 * */

#include "linkedlist.c"

Node* InsertionSort(Node* head){
    Node *res=NULL;
    Node* temp=head;
    while(temp!=NULL){
        int data = temp->data;
        if(res==NULL){
            res=push(res,data);
            temp=temp->next;
            continue;
        }
        Node* h1=res;
        while(h1!=NULL && h1->data<data){
            //head case
            if(h1->data>data){
                Node* new_node=(Node*)malloc(sizeof(Node));
                new_node->data=data;
                new_node->next=h1;
                res=new_node;
                
                break;
            }
            if(h1->next!=NULL && h1->next->data>data){
                Node* new_node=(Node*)malloc(sizeof(Node));
                new_node->data=data;
                new_node->next=h1->next;
                h1->next=new_node;
            }
            // insert at last
            if(h1->next==NULL)res=push(res,data);
            h1=h1->next;
        }
        temp=temp->next;
    }
    return res;
}

int main(){
    Node *head=NULL;
    head=push(head,4);
    head=push(head,7);
    head=push(head,20);
    head=push(head,12);
    head=push(head,5);

    head=InsertionSort(head);
    printList(head);
    return 0;
}