/**
 * check if sum tree : left_subtree_sum+right_subtree_sum=root_value
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
#include "bin_utility.c"
int sum(Node* root){
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)return root->data;
    // return sum(root->left)+root->data+sum(root->right);
    return 2*root->data;
}
int isSumTree(Node* root){
    if(root==NULL)return 1;
    if(root->left==NULL && root->right==NULL)return 1;
    int lsum = sum(root->left);
    int rsum = sum(root->right);

    if(root->data==lsum+rsum && (isSumTree(root->left)&& isSumTree(root->right))){
        return 1;
    }else{
        return 0;
    }
    return 0;
}
int main(){
    struct Node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        printf("The given tree is a SumTree.\n");
    else
        printf("The given tree is not a SumTree.\n");
}