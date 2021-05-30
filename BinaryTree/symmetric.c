/**
 * Check if given binary tree is symmetric
 * @author TheAndroCoder
 * */

#include "bin_utility.c"

int isSymmetric(Node* root){
    if(root==NULL)return 1;
    if(root->left==NULL && root->right==NULL)return 1;
    
    enqueue(root->left);
    enqueue(root->right);

    while(!isEmpty()){
        Node* left = dequeue();
        Node* right = dequeue();
        if(left==NULL && right==NULL)continue;
        if((left==NULL && right!=NULL) || (left!=NULL && right==NULL))return 0;

        if(left->data!=right->data)return 0;

        enqueue(left->left);
        enqueue(right->right);
        enqueue(left->right);
        enqueue(right->left);


    }
    return 1;
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
  
    if(isSymmetric(root))
        printf("It is Symmetric\n");
    else
        printf("It is not Symmetric\n");
    return 0;
}