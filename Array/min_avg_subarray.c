/**
 * Minimum average subarray of size k
 * @author TheAndroCoder
 * */
#include<stdio.h>
void minAvg(int a[],int k,int n){
    // window of size k
    int sum=0;
    int start=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    for(int i=1;i<n-k;i++){
        int c=sum;
        c-=a[i-1];
        c+=a[i+k-1];
        if(c<sum){
            sum=c;
            start=i;
        }
    }
    printf("Range[%d,%d]\n",start,start+k-1);

}
int main(){
    int arr[] = { 3, 7, 90, 20, 10, 50, 40 }; 
    int k = 3; // Subarray size 
    int n = sizeof(arr)/ sizeof(int);
    minAvg(arr,k,n);
    return 0;
}