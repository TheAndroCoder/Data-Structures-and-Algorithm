/**
 * Sum of all nodes in Binary tree
 * @author TheAndroCoder
 * */

#include "bin_utility.c"
int addBT(Node* root){
    if(root==NULL)return 0;
    return root->data+addBT(root->left)+addBT(root->right);
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
  
    int sum = addBT(root);
    printf("Sum : %d\n",sum);
    return 0;
}