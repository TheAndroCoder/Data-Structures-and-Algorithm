/**
 * Check for Dead End
 * @author TheAndroCoder
 * */

#include "BST.c"
#include<limits.h>

int deadEndUtil(Node* root,int l,int r){
    if(root==NULL)return 0;

    if(l==r)return 1;
    return deadEndUtil(root->left,l,root->data-1)||deadEndUtil(root->right,root->data+1,r);
}
int deadEnd(Node* root){
    if(root==NULL)return 0;
    return deadEndUtil(root,INT_MIN,INT_MAX);
}
int main(){
    Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    if (deadEnd(root))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}