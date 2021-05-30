/**
 * Basic utlity functions of BST
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;


void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
Node* newNode(int value){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
Node* insert(Node* root,int value){
    if(root==NULL)return newNode(value);
    if(root->data<value)root->right=insert(root->right,value);
    else root->left=insert(root->left,value);
    return root;
}
Node* inorderSuccessor(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
/**
 * Three possibilities arise..
 * a) Node to be deleted is leaf Node
 * b) Node to be deleted has one child
 * c) Node to be deleted has 2 children
 * */
Node* delete(Node* root,int data){
    if(root==NULL)return root;
    if(data<root->data)root->left=delete(root->left,data);
    else if(data>root->data)root->right=delete(root->right,data);
    else{
        // key found
        if(root->left==NULL){
            // return root->right
            Node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        // both children are non-null

        Node* temp=inorderSuccessor(root->right);
        root->data=temp->data;
        //free(temp);
        root->right=delete(root->right,root->data);
    }
    return root;
}
// int main(){
//     Node* root=NULL;
//     root=insert(root,20);
//     insert(root,50);
//     insert(root,10);
//     insert(root,5);
//     inorder(root);
//     printf("\n");
//     root=delete(root,20);
//     inorder(root);
//     return 0;
// }