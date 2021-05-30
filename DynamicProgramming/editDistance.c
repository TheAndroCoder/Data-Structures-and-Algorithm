/**
 * Edit Distance
 * @author TheAndroCoder
 * */

#include<stdio.h>
int min_ele(int a,int b){
    return a>b?b:a;
}
int min_dist(char str1[],char str2[],int n1,int n2){
    int dp[n1][n2];
    // first col and first row (empty string)
    for(int i=0;i<n1;i++)dp[i][0]=i;
    for(int i=0;i<n2;i++)dp[0][i]=i;
    


    for(int i=1;i<n1;i++){
        for(int j=1;j<n2;j++){
            if(str1[i-1]!=str2[j-1]){
                // min of up, left, diag +1
                int min = min_ele(dp[i][j-1],dp[i-1][j]);
                min = min_ele(min,dp[i-1][j-1]);
                dp[i][j]=min+1;
                //printf("Setting %d to dp[%d][%d]\n",min+1,i,j);
            }else{
                dp[i][j]=dp[i-1][j-1];
                //printf("Setting %d to dp[%d][%d]\n",dp[i-1][j-1],i,j);
            }
        }
    }

    // for(int i=0;i<n1;i++){
    //     for(int j=0;j<n2;j++){
    //         printf("%d\t",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[n1-1][n2-1];
}
int main(){
    char str1[] = "CART";
    char str2[] = "MARCH";
    int l1=sizeof(str1)/sizeof(char);
    int l2=sizeof(str2)/sizeof(char);
    //printf("l1,l2=%d,%d\n",l1,l2);
    printf("Min Distance : %d\n",min_dist(str1,str2,l1,l2));
}