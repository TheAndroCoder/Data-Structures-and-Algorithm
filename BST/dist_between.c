/**
 * Distance between two nodes in BST
 * @author TheAndroCoder
 * */

#include "BST.c"
int distofnode(Node* root,int key){
    if(root->data==key)return 0;
    else if(root->data>key)return 1+distofnode(root->left,key);
    return 1+distofnode(root->right,key);
}
int distance(Node* root,int a ,int b){
    if(root->data>a && root->data>b)return distance(root->left,a,b);
    if(root->data<a && root->data<b)return distance(root->right,a,b);

    if(root->data>a && root->data<b){
        return distofnode(root,a)+distofnode(root,b);
    }
}
int main(){
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);
    int a = 5, b = 55;
    printf("Distance : %d\n",distance(root,5,35));
    return 0;
}