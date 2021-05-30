/**
 * Print nodes at odd levels
 * @author TheAndroCoder
 * */

#include "bin_utility.c"

void printOddNodes(Node* root,int odd){
    if(root==NULL)return;
    if(odd)printf("%d\t",root->data);
    printOddNodes(root->left,!odd);
    printOddNodes(root->right,!odd);
}
void printFullNodes(Node* root){
    if(root==NULL)return;
    if(root->left!=NULL && root->right!=NULL){
        printf("%d\t",root->data);
    }
    printFullNodes(root->left);
    printFullNodes(root->right);
}
int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printOddNodes(root,1);
    printf("\nPrinting Full Nodes\n");
    printFullNodes(root);
    printf("\n");
    return 0;
}