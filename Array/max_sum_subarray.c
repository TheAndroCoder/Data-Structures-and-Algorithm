/**
 * Kadane's Algorithm : max sum sub-array
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<limits.h>
int maxSum(int a[],int n){
    int max_so_far=0;
    int max_ending_here=0;
    for(int i=0;i<n;i++){
        max_ending_here=max_ending_here+a[i];
        //max_ending_here=max_ending_here<max_so_far?max_so_far:max_ending_here;
        max_so_far=max_ending_here>max_so_far?max_ending_here:max_so_far;
        if(max_ending_here<0)max_ending_here=0;
    }
    return max_so_far;
}
int main(){
    int a[] = {-2, -3, 1, -1, -2, 1, 5, 3};
    int n = sizeof(a)/sizeof(int);
    printf("Maximum Contiguous sum is %d\n",maxSum(a,n));
    return 0;
}