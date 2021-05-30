/**
 * Count number of 1's in binary array
 * @author TheAndrocoder
 * */

#include<stdio.h>

int count(int a[],int low,int high){
    if(low>high)return -1;
    int mid = low+(high-low)/2;
    if(a[mid]==0 && a[mid+1]==1)return mid+1;
    if(a[mid]==1 && a[mid-1]==0)return mid;
    if(a[mid]==0 && a[high]==1)return count(a,mid+1,high);
    return count(a,low,mid-1);
}
int main(){
    int arr[]={0,0,0,0,0,0,0,0,0,1};
    int len=10;
    printf("Count of 1's = %d\n",len-count(arr,0,len-1));
    return 0;
}