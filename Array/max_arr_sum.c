/**
 * Max array sum with all possible rotations
 * @author TheAndroCoder
 * */

#include<stdio.h>

int maxSum(int a[],int n){
    int sum=0;
    int r0 = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        r0+=(i*a[i]);
    }
    int max=r0;
    // R[j]-R[j-1]=arrSum-n*a[n-j]
    for(int i=1;i<n;i++){
        r0 = r0+sum-(n*a[n-i]);
        max=max>r0?max:r0;
    }
    return max;
}

int main(){
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Max Sum : %d\n",maxSum(arr,n));
    return 0;
}