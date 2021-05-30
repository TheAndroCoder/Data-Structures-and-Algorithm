/**
 * Search in Sorted and single rotated Array
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>

int findPivot(int a[],int low,int high){
    if(high<low)return -1;
    if(high==low)return low; // only one element present
    int mid=low+(high-low)/2;
    //printf("Low=%d, mid=%d, high=%d",low,mid,high);
    if(a[mid]>a[mid+1]){
        return mid;
    }
    if(a[mid]<a[mid-1]){
        return mid-1;
    }
    if(a[low]>a[mid])return findPivot(a,low,mid-1);
    return findPivot(a,mid+1,high);
}

int binSearch(int a[],int low,int high,int key){
    if(low>high)return -1;
    int mid=low+(high-low)/2;
    if(a[mid]==key)return mid;
    if(a[mid]>key)return binSearch(a,low,mid-1,key);
    return binSearch(a,mid+1,high,key);
}

int pivotedBinSearch(int a[],int n,int key){
    int pivot = findPivot(a,0,n-1);
    // now based on this pivot do binary-search with left and right array
    int ind1 = binSearch(a,0,pivot,key);

    int ind2 = binSearch(a,pivot+1,n-1,key);
    return ind1!=-1?ind1:ind2;
}

int main(){
    int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 }; 
    int n = sizeof(arr1) / sizeof(arr1[0]); 
    int key = 2;

    printf("Index of element is %d\n",pivotedBinSearch(arr1,n,key));
    return 0;
}