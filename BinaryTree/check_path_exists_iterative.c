/**
 * Check path exists iterative method
 * @author TheAndroCoder
 * */

#include "bin_utility.c"

int existsPath(Node* root,int a[],int n){
    if(a[0]!=root->data)return 0;
    int index=1;
    while(index<n && root!=NULL){
        if(root->left!=NULL && root->left->data==a[index++]){
            root=root->left;
        }else if(root->right!=NULL && root->right==a[index++]){
            root=root->right;
        }else{
            return 0;
        }
    }
    if(index==n-1)return 1;
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
    int exists = existsPath(root,arr,n);
    return 0;
}