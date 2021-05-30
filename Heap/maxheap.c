/**
 * MaxHeap implementation (basic utility functions)
 * @author TheAndroCoder
 * */

#include<stdio.h>
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
    while(i!=0 && a[parent(i)]<a[i]){
        swap(&a[i],&a[parent(i)]);
        i=parent(i);
    }
}
void heapify(int i){
    int l=left(i);
    int r=right(i);
    int largest=i;
    if(l<size && a[l]>a[largest])largest=l;
    if(r<size && a[r]>a[largest])largest=r;
    if(largest!=i){
        swap(&a[i],&a[largest]);
        heapify(largest);
    }
}
int isHeap(){
    // for every element check is left and right child are smaller
    for(int i=0;i<size;i++){
        int p=i;
        int l=left(i);
        int r=right(i);
        if(l<size && a[l]>a[p])return 0;
        if(r<size && a[r]>a[p])return 0;
    }
    return 1;
}
int getMax(){
    return a[0];
}
int extractMax(){
    int root=a[0];
    a[0]=a[--size];
    heapify(0);
    return root;
}
int main(){
    insert(3);
    insert(2);
    insert(1);
    insert(15);
    printf("getMax()=%d\n",getMax());
    printf("extractMax()=%d\n",extractMax());
    printf("getMax()=%d\n",getMax());
    printf("isMaxHeap? = %d\n",isHeap());
    return 0;
}