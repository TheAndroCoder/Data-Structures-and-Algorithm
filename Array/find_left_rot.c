/**
 * Quickly Find multiple left rotations of an array
 * @author TheAndroCoder
 * */

#include<stdio.h>

void rotate(int a[],int n,int k){
    for(int i=k;i<k+n;i++){
        printf("%d ",a[i%n]);
    }
    printf("\n");
}

int main(){
    int arr[]={1,3,5,7,9};
    int n = sizeof(arr)/sizeof(int);
    rotate(arr,n,4);
    return 0;
}