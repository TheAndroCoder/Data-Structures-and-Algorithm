/**
 * All Paths from root to leaf (for distinct node values)
 * @author TheAndroCoder
 * */

#include "bin_utility.c"

void printArray(int a[],int p){  
    printf("%d\t",p);
    while(a[p]!=0 && p!=0){
        printf("%d\t",a[p]);
        p=a[p];
    }
    printf("\n");
}
void printRootToLeaf(Node* root){
    if(root==NULL)return;
    push(root);
    
    Node* temp=NULL;
    int parent[20]={0};
    //int index=0;
    int a[20]={0};
    a[root->data]=0;
    while(!empty()){
        temp=pop();
        if(temp->left==NULL && temp->right==NULL){
            // leaf
            printArray(a,temp->data);
        }
        if(temp->left){
            push(temp->left);

            a[temp->left->data]=temp->data;
            //continue;
        }
        if(temp->right){
            push(temp->right);
            a[temp->right->data]=temp->data;
            
        }
    }
}
int main(){
    Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(7);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
  
    printRootToLeaf(root);
    return 0;
}