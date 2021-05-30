/**
 * Remove outside range
 * @author TheAndroCoder
 * */

#include "BST.c"

Node* removeOutsideRange(Node* root,int min,int max){
    if(root==NULL)return root;

    root->left=removeOutsideRange(root->left,min,max);
    root->right=removeOutsideRange(root->right,min,max);

    if(root->data<min){
        Node* temp=root->right;
        free(root);
        return temp;
    }
    if(root->data>max){
        Node* temp=root->left;
        free(root);
        return temp;
    }
    return root;
}
int main(){
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    inorder(root);
    printf("\n");
    root = removeOutsideRange(root, -10, 13);
    inorder(root);
    printf("\n");

    return 0;
}