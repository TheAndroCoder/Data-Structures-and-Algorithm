/**
 * Longest common subsequence
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b){
    return a>b?a:b;
}
void print(int lcs[][10],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d\t",lcs[i][j]);
        }
        printf("\n");
    }
}
int lcs(char s1[],char s2[],int n,int m){
    // n=6, m=7
    int lcs[n+1][m+1]; // lcs[7][8]
    //memset(lcs,0,sizeof(int)*(n)*(m));
    // first row =0 and first column=0;
    //for(int i=0;i<n+1;i++)lcs[0][i]=0;
    //for(int i=0;i<m+1;i++)lcs[i][0]=0;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                lcs[i][j]=0;
                continue;
            }
            //printf("%d %d\n",i,j);
            if(s1[i-1]==s2[j-1]){
                printf("%d %d\n",i,j);
                lcs[i][j]=lcs[i-1][j-1]+1;
            }else{
                // max of left and top cell value
                lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
            }
        }
    }
    print(lcs,n+1,m+1);
    //
    return lcs[n][m];
}
int main(){
    char s1[] = "AGGTAB";
    char s2[]="GXTXAYB";
    int len_s1 = sizeof(s1)/sizeof(char);
    int len_s2=sizeof(s2)/sizeof(char);
    printf("Longest Common SubSequence length : %d \n",lcs(s1,s2,len_s1-1,len_s2-1)); 
    return 0;
}