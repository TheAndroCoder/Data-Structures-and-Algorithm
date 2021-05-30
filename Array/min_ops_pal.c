/**
 * Minimum number of operations to make array palindrome
 * @author
 * */

#include<stdio.h>

int min_ops(int a[],int n){
    int count=0;
    int i=0,j=n-1;
    while(i<j){
        if(a[i]==a[j]){
            i++;j--;
        }else if(a[i]>a[j]){
            // merge at j side (always merge at smaller side)
            j--;
            a[j]+=a[j+1];
            count++;
        }else{
            // merge at i side (always merge at smaller side)
            i++;
            a[i]+=a[i-1];
            count++;
        }
    }
    return count;
}

int main(){
    int arr[] = {1, 13,8,5, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum operations needed = %d\n",min_ops(arr,n));
    return 0;
}