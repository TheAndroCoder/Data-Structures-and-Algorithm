/**
 * Next Greater element after a given index
 * @author TheAndroCoder
 * */
#include "stack.c"
void next_greater(int next[],int a[],int n){
    push(0);
    for(int i=1;i<n;i++){
        while(!isEmpty()){
            int curr = peek();
            if(a[curr]<a[i]){
                next[curr]=i;
                pop();
            }
            else break;
        }
        push(i);
    }
    while(!isEmpty()){
        int curr=peek();
        next[curr]=-1;
        pop();

    }
}
int query(int a[],int next[],int n,int q){
    int pos = next[q];
    if(pos==-1)return pos;
    return a[pos];
}
int main(){
    int a[] = {3, 4, 2, 7,
               5, 8, 10, 6 };
 
    int n = sizeof(a) / sizeof(a[0]);
 
    int next[n];
    next_greater(next,a,n);
    printf("Next greater to 3 : %d\n",query(a,next,n,3));
    return 0;
}