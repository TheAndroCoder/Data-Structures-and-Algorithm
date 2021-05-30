/**
 * Subtree with Sum X
 * 
 * */

#include "bin_utility.c"

int sumExistsUtil(Node* root,int* curr,int sum){
    if(root==NULL){
        *curr=0;
        return 0;
    }
    int left=0,right=0;
    return (sumExistsUtil(root->left,&left,sum)||sumExistsUtil(root->right,&right,sum)||((*curr=left+right+root->data)==sum));
}
int sumExists(Node* root,int sum){
    int curr=0;
    return sumExistsUtil(root,&curr,sum);
    
}
int main(){
    Node *root = newNode(8);
    root->left    = newNode(5);
    root->right   = newNode(4);
    root->left->left = newNode(9);
    root->left->right = newNode(7);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(12);
    root->left->right->right->right = newNode(2);
    root->right->right = newNode(11);
    root->right->right->left = newNode(3);
    int sum = 22;

    if(sumExists(root,sum)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}