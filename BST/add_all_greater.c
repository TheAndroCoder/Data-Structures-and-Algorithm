/**
 * Add all greater elements of BST
 * @author TheAndroCoder
 * */

#include "BST.c"

void modifyBST(Node* root,int* sum){
    if(root==NULL)return;

    modifyBST(root->right,sum);

    *sum=*sum+root->data;
    root->data=*sum;
    modifyBST(root->left,sum);
}
int main(){
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int sum=0;
    modifyBST(root,&sum);
  
    // print inoder tarversal of the modified BST
    inorder(root);
    return 0;
}