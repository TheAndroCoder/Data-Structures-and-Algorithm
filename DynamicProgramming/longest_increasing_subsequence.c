/**
 * Longest Increasing Subsequence
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
int lis(int a[],int n){
    int lis[n];
    for(int i=0;i<n;i++)lis[i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                lis[i]=lis[j]+1>lis[i]?lis[j]+1:lis[i];
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++)max=lis[i]>max?lis[i]:max;
    return max;
}
int main(){
    int arr[]={10, 22, 9, 33, 21, 50, 41, 60};
    int n=sizeof(arr)/sizeof(int);
    printf("Length of LIS : %d\n",lis(arr,n));
    return 0;
}