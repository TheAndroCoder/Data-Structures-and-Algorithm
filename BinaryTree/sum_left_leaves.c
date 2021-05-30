/**
 * Sum of all the left leaves of Btree
 * 
 * */

#include "bin_utility.c"

int isLeaf(Node* node){
    if(node->left==NULL && node->right==NULL)return 1;
    return 0;
}
int left_leaves_sum(Node* root){
    if(root==NULL)return 0;
    int sum=0;
    if(root->left && isLeaf(root->left)){
        sum+=root->left->data;
    }else{
        sum+=left_leaves_sum(root->left);
    }
    sum+=left_leaves_sum(root->right);
    return sum;

}
int main(){
    Node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(12);

    printf("LeftLeaves Sum : %d\n",left_leaves_sum(root));
    return 0;
}