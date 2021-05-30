#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* newNode(int data){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}


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


//** Stack Implementation **//
int top=-1;
Node* arr[100];
void push(Node* n){
    arr[++top]=n;
}
Node* pop(){
    if(top!=-1)return arr[top--];
    return NULL;
}
int empty(){
    return top==-1;
}