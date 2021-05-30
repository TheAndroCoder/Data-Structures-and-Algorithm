/**
 * Mirror Tree ( are trees A and B mirror trees?)
 * @author TheAndroCoder
 * */

#include "bin_utility.c"
int isMirror(Node* a,Node* b){
    if(a==NULL && b==NULL)return 1;
    if(a==NULL || b==NULL)return 0;
    return a->data==b->data&&isMirror(a->left,b->right)&& isMirror(a->right,b->left);
}
int main(){
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);
  
    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);
  
    int mirr=isMirror(a, b);
    if(mirr)printf("They are mirrors\n");
    else printf("They are not mirrors\n");
    return 0;
}