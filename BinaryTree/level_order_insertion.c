/**
 * Level order insertion in binary tree
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// *** Queue Implementation ****//
#define MAX_SIZE 100
Node* a[MAX_SIZE];
int rear=-1;
int front=-1;

void enqueue(Node* n){
    if(rear==MAX_SIZE-1){
        printf("Size exceeded while inserting %d\n",n->data);
        return;
    }
    a[++rear]=n;
}
Node* dequeue(){
    if(front==rear){
        printf("Empty Queue");
        return NULL;
    }
    return a[++front];
}
Node* peek(){
    if(front==rear){
        printf("Empty Queue");
        return NULL;
    }
    return a[front+1];
}
int isEmpty(){
    return front==rear;
}
void emptyQueue(){
    front=-1;
    rear=-1;
}
//**** Queue implementation ends ***//
Node* new_node(int value){
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}
Node* insert(Node* root,int data){
    if(root==NULL){
        root=new_node(data);
        return root;
    }
    Node* temp=NULL;
    emptyQueue();
    enqueue(root);
    while(!isEmpty()){
        temp=dequeue();
        if(temp->left==NULL){
            temp->left=new_node(data);
            break;
        }else{
            enqueue(temp->left);
        }
        if(temp->right==NULL){
            temp->right=new_node(data);
            break;
        }else{
            enqueue(temp->right);
        }
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
int main(){
    Node* root=NULL;
    root=insert(root,3);
    root=insert(root,5);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    inorder(root);
    return 0;
}