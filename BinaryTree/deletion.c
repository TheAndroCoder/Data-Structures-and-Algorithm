/**
 * Delete a key from Binary Tree
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// *** Queue Implementation starts *** //
#define MAX_SIZE 100
int rear=-1;
int front=-1;
Node* a[MAX_SIZE];
void enqueue(Node* n){
    if(rear==MAX_SIZE-1)return;
    a[++rear]=n;
}
Node* dequeue(){
    if(front==rear)return NULL;
    return a[++front];
}
int isEmpty(){
    return front==rear;
}
// *** Queue Implementation ends *** //


Node* newNode(int value){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    //printf("\n");
}
void deleteDeepest(Node* root,Node* d_node){
    front=-1;
    rear=-1;
    enqueue(root);
    Node* temp=NULL;
    while(!isEmpty()){
        temp=dequeue();
        if(temp==d_node){
            temp=NULL;
            free(d_node);
            return;
        }
        if(temp->right!=NULL && temp->right==d_node){
            temp->right=NULL;
            free(d_node);
            return;
        }else{
            enqueue(temp->right);
        }

        if(temp->left!=NULL && temp->left==d_node){
            temp->left=NULL;
            free(d_node);
            return;
        }else{
            enqueue(temp->left);
        }
    }
}
Node* delete(Node* root,int key){
    if(root==NULL)return NULL;
    if(root->left==NULL && root->right==NULL){
        if(root->data==key){
            return NULL;
        }
        return root;
    }
    front=-1;
    rear=-1;
    enqueue(root);
    Node* temp=NULL;
    Node* key_node=NULL;
    while(!isEmpty()){
        temp=dequeue();
        if(temp->data==key){
            key_node=temp;
            // no break statement here snce we need last node in temp, level order last will be last node
        }
        if(temp->left!=NULL)enqueue(temp->left);
        if(temp->right!=NULL)enqueue(temp->right);
    }
    if(key_node!=NULL){
        int x=temp->data;
        deleteDeepest(root,temp);
        key_node->data=x;
    }

    return root;
}
int main(){
    Node* root=newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    inorder(root);
    printf("\n");
    root=delete(root,7);

    inorder(root);
    printf("\n");
    return 0;
}