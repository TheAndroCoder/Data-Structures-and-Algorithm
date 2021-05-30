/**
 * Sum of pair=x in sorted and rotated array
 * @author TheAndroCoder
 * */
#include<stdio.h>
int findPivot(int a[],int low,int high){
    // finding pivot with binSearch , can use linear search also
    if(low>high)return -1;
    if(high==low)return low;
    int mid=low+(high-low)/2;
    if(a[mid]>a[mid+1])return mid;
    if(a[mid]<a[mid-1])return mid-1;
    if(a[low]>a[mid])return findPivot(a,low,mid-1);
    return findPivot(a,mid+1,high);
}

int findPair(int a[],int n,int sum){
    int pivot=findPivot(a,0,n-1);
    int l=pivot,r=pivot+1;
    while(l!=r){
        //printf("l=%d,r=%d\n",l,r);
        if(a[l]+a[r]==sum)return 1;
        if(a[l]+a[r]>sum)l--;
        else if(a[l]+a[r]<sum)r++;
        if(l==-1)l=n-1;
        if(r==n)r=0;
    }
    return 0;
}

int main(){
    int arr[] = {11, 15, 6, 8, 9, 10}; 
    int sum = 17; 
    int n = sizeof(arr)/sizeof(arr[0]);

    if(findPair(arr,n,sum)){
        printf("Pair found\n");
    }else{
        printf("Pair not found\n");
    }
    return 0;
}