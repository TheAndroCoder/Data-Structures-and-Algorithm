/**
 * Check if preorder traversal is valid for a BST or not
 * @author TheAndroCoder
 * */

#include "stack.c"
#include<limits.h>
int canRepresentBST(int a[],int n){
    int root=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]<root)return 0;
        while(!isEmpty() && a[i]>peek()){
            root=pop();
            printf("Poped %d from stack\n",root);
        }
        printf("Pushed %d to stack\n",a[i]);
        push(a[i]);
    }
    return 1;
}
int main(){
    int pre1[] = {40, 30, 35, 36, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    printf("Can represent BST ? : %d\n",canRepresentBST(pre1,n));
}