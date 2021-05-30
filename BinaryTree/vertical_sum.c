/**
 * Vertical sum of Binary Tree
 * 
 * */

#include "bin_utility.c"
int a[20]={0};
void verticalSum(Node* root){
    if(root==NULL)return;

}
int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
  
    printf("Following are the values of vertical"
            " sums with the positions of the "
            "columns with respect to root\n");
    verticalSum(root);
    return 0;
}