/**
 * Minimum number of swaps to bring elemnts less than K together
 * @author TheAndroCoder
 * */

#include<stdio.h>

int minSwaps(int a[],int n,int k){
    // how many elements are there <=k
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]<=k)count++;
    }
    //unwanted elements in current window
    int window=count;
    int unwanted=0;
    for(int i=0;i<window;i++){
        if(a[i]>k)unwanted++;
    }
    //printf("Unwanted %d\n",unwanted);
    int ans=unwanted;
    int j=count+1,i=1;
    while(j<n){
        if(a[j]>k)++unwanted;
        if(a[i]>k)--unwanted;
        ans=ans<unwanted?ans:unwanted;
        printf("Swaps in window[%d,%d]=%d\n",i,j,ans);
        i++;
        j++;
    }
    return ans;
}

int main(){
    int arr[] = {2, 7, 9, 5, 8, 7, 4}; 
    int n = sizeof(arr) / sizeof(int); 
    int k = 5; 

    printf("MinSwaps Required: %d\n",minSwaps(arr,n,k));
}