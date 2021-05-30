/**
 * Rotate an array cyclically by one
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
void rotate(int a[],int n){
    int last=a[n-1];
    for(int i=n-1;i>0;i--){
        a[i]=a[i-1];
    }
    a[0]=last;
}

int main(){
    int n=10;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    rotate(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}