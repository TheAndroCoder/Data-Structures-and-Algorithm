/**
 * Kth Largest sum subarray
 * @author TheAndroCoder
 * */

#include<stdio.h>

// TODO : Implement Priority Queue


int kthLargest(int a[],int n,int k){
    // make sum[]
    int sum[n+1];
    sum[0]=0;
    sum[1]=a[0];
    for(int i=2;i<=n;i++)sum[i]=sum[i-1]+a[i-1];

    int largest=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int sumArr=sum[j]-sum[i-1];
        }
    }
    return largest;
}

int main(){
    int a[] = { 10, -10, 20, -40 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;
    printf("Kth Largest sum : %d",kthLargest(a,n,k));
    return 0;
}