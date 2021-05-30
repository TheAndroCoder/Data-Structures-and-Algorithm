/**
 * Sum longest path
 * @author TheAndroCoder
 * */

#include "bin_utility.c"
void sum_longest_util(Node* root,int sum,int len,int* maxLen,int* maxSum){
    if(root==NULL){
        if(*maxLen<len){
            *maxLen=len;
            *maxSum=sum;
        }else if(*maxLen==len && *maxSum<sum){
            *maxSum=sum;
        }
        return;
    }
    sum_longest_util(root->left,sum+root->data,len+1,maxLen,maxSum);
    sum_longest_util(root->right,sum+root->data,len+1,maxLen,maxSum);
}
int sum_longest(Node* root){
    if(root==NULL)return 0;
    int maxLen=0,maxSum=0;
    sum_longest_util(root,0,0,&maxLen,&maxSum);
    return maxSum;
}
int main(){
    Node* root = newNode(4);         /*        4        */
    root->left = newNode(2);         /*       / \       */
    root->right = newNode(5);        /*      2   5      */
    root->left->left = newNode(7);   /*     / \ / \     */
    root->left->right = newNode(1);  /*    7  1 2  3    */
    root->right->left = newNode(2);  /*      /          */
    root->right->right = newNode(3); /*     6           */
    root->left->right->left = newNode(6);

    printf("Sum longest path : %d\n",sum_longest(root));
    return 0;
}