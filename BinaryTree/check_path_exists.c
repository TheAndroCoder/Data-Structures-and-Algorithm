/**
 * Check path exists or not from root to leaf node given by array
 * @author TheAndroCoder
 * */

#include "bin_utility.c"

int existPath(Node* root,int a[],int n,int index){
    if(root==NULL)return n==0;
    if(root==NULL || index==n)return 0;
    if(root->left==NULL && root->right==NULL){
        if(root->data==a[index] && index==n-1)return 1;
        return 0;
    }
    return ((index<n)&& (root->data==a[index]) && (existPath(root->left,a,n,index+1) || existPath(root->right,a,n,index+1)));

}
int main(){
    int arr[] = {5, 8, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->left->left->left = newNode(1);
    root->right->left = newNode(6);
    root->right->left->right = newNode(7);
    if(existPath(root,arr,n,0)){
        printf("Path Exists\n");
    }else{
        printf("Path doesnot Exist\n");
    }
    return 0;
}