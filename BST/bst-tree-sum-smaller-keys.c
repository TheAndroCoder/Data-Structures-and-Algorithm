/**
 * BST to Binary tree with sum of all smaller nodes
 * @author TheAndroCoder
 * */

#include "BST.c"
void addSmallerUtil(Node* root,int *sum){
    if(root==NULL)return;
    
    addSmallerUtil(root->left,sum);
    *sum=*sum+root->data;
    root->data=*sum;
    addSmallerUtil(root->right,sum);
}
void addSmaller(Node* root){
    if(root==NULL)return;
    int sum=0;
    addSmallerUtil(root,&sum);
}
int main(){
    Node* root = newNode(9);
    root->left = newNode(6);
    root->right = newNode(15);

    inorder(root);
    printf("\n");
    addSmaller(root);
    inorder(root);
    printf("\n");
}