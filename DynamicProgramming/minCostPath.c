/**
 * Min cost path to reach (m,n) from (0,0)
 * @author TheAndroCoder
 * */

#include<stdio.h>
int min(int a,int b,int c){
    int m=a<b?a:b;
    m=m<c?m:c;
    return m;
}
int minCost(int cost[][3],int n,int m){
    int dp[n][m];
    dp[0][0]=cost[0][0];
    for(int i=1;i<n;i++)dp[i][0]=cost[i][0]+dp[i-1][0];
    for(int i=1;i<m;i++)dp[0][i]=cost[0][i]+dp[0][i-1];

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int m=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]);
            dp[i][j]=cost[i][j]+m;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         printf("%d\t",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[n-1][m-1];
}
int main(){
    int cost[3][3]={{1,2,3},{4,8,2},{1,5,3}};
    printf("Min Cost : %d\n",minCost(cost,3,3));
    return 0;
}