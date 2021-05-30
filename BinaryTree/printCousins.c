/**
 * Print siblings of a given node (not cousins)
 * @author TheAndroCoder
 * */

#include "bin_utility.c"
int getLevel(Node* root,Node* node,int level){
    if(root==NULL)return 0;
    if(root==node)return level;
    int downLevel = getLevel(root->left,node,level+1);
    if(downLevel!=0)return downLevel;
    return getLevel(root->right,node,level+1);
}
void printGivenLevel(Node* root,Node* node,int level){
    if(root==NULL || level<2)return;
    if(level==2){
        if(root->left==node || root->right==node)return;
        if(root->left!=NULL)printf("%d\t",root->left->data);
        if(root->right!=NULL)printf("%d\t",root->right->data);
    }else if(level>2){
        printGivenLevel(root->left,node,level-1);
        printGivenLevel(root->right,node,level-1);
    }
}
void printCousins(Node* root, Node* node){
    int level = getLevel(root,node,1);
    //printf("Level : %d\n",level);
    printGivenLevel(root,node,level);
}
int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
  
    printCousins(root, root->left->right);
    return 0;
}