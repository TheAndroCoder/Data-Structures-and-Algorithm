/**
 * Largest Subtree Sum
 * @author TheAndroCoder
 * */

#include "bin_utility.c"
int largest_subtree_sum_util(Node* root,int* ans){
    if(root==NULL)return 0;

    int ls = largest_subtree_sum_util(root->left,ans);
    int rs=largest_subtree_sum_util(root->right,ans);
    int curr = ls+rs+root->data;
    *ans=*ans>curr?*ans:curr;
    return curr;
}
int largest_subtree_sum(Node* root){
    int ans=-100;
    largest_subtree_sum_util(root,&ans);
    return ans;
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
  
    printf("Largest subtree sum : %d\n",largest_subtree_sum(root));
    return 0;
}