/**
 * Minimum Coins change to make a given amount
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<limits.h>
int min(int a,int b){
    return a>b?b:a;
}
int minChange(int coins[],int n,int amount){
    int dp[n+1][amount+1];
    for(int i=0;i<amount+1;i++)dp[0][i]=INT_MAX;
    for(int i=0;i<n+1;i++)dp[i][0]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<amount+1;j++){
            if(coins[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
            //dp[i][j]=inc<exc?inc:exc;
        }
    }
    return dp[n][amount];
}
int main(){
    int coins[]={1,2,5};
    int amt=6;
    printf("Minimum number of coins needed : %d\n",minChange(coins,3,amt));
    return 0;
}