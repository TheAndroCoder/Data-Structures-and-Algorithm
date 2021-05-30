/**
 * Basic heap functions
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int a[MAX_SIZE];
int size=0;
int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void insert(int key){
    a[size++]=key;
    int i=size-1;
    while(i!=0 && a[parent(i)]>a[i]){
        swap(&a[i],&a[parent(i)]);
        i=parent(i);
    }
}
int getMin(){
    return a[0];
}
void heapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l<size && a[l]<a[smallest])smallest=l;
    if(r<size && a[r]<a[smallest])smallest=r;
    if(smallest!=i){
        swap(&a[i],&a[smallest]);
        heapify(smallest);
    }
}
int extractMin(){
    if(size==1){
        size=0;
        return a[0];
    }
    int root=a[0];
    a[0]=a[size-1];
    size--;
    heapify(0);
    return root;
}
int main(){
    insert(3);
    insert(2);
    insert(1);
    insert(15);
    printf("getMin()=%d\n",getMin());
    printf("extractMin()=%d\n",extractMin());
    printf("getMin()=%d\n",getMin());
    return 0;
}