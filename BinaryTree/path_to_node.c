/**
 * Path to given node in BinTree
 * @author TheAndroCoder
 * */

#include "bin_utility.c"
int hasPath(Node* root,int x,int a[],int index){
    if(root==NULL)return 0;
    //int ind=*index;
    a[index]=root->data;
    index=index+1;
    if(root->data==x)return 1;
    if(hasPath(root->left,x,a,index)||hasPath(root->right,x,a,index))return 1;

    index--;
    return 0;
}
void printPath(Node* root,int x){
    int a[100]={0};
    //int index=0;
    if(hasPath(root,x,a,0)){
        int i=0;

        while(a[i]!=0){
            printf("%d\t",a[i++]);
        }
    }else{
        printf("No Path\n");
    }
}
int main(){
    // binary tree formation
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
          
    int x = 5;
    printPath(root, x);
    return 0;
}