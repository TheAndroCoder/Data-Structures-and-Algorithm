/**
 * Check if tree is perfect Binary Tree
 * All leaf nodes should be in same level and all internal nodes have 2 children
 * @author TheAndroCoder
 * */

#include "bin_utility.c"
int findDepth(Node* root){
    if(root==NULL)return 0;
    int d=0;
    while(root!=NULL){
        d++;
        root=root->left;
    }
    return d;
}
int isPerfectRec(Node* root,int depth,int level){
    if(root==NULL)return 1;
    if(root->left==NULL && root->right==NULL){
        return depth==level+1;
    }
    if(root->left==NULL || root->right==NULL)return 0;

    return isPerfectRec(root->left,depth,level+1)&&isPerfectRec(root->right,depth,level+1);
}
int isPerfect(Node* root){
    int d=findDepth(root);
    return  isPerfectRec(root,d,0); // root,depth,level passed as param
}

int main(){
    Node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
  
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);
    inorder(root);
    if (isPerfect(root))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}