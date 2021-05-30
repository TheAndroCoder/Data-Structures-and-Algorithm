/**
 * Find minSources of starting point for traversing each point in this matrix
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
typedef struct pair{
    int x,y;
}pair;
typedef struct Pair{
    int e;
    pair* p;
}Pair;
void __sort(Pair p[],int size){
    printf("Before sorting\n");
    for(int i=0;i<size;i++){
        printf("%d,(%d,%d)\n",p[i].e,p[i].p->x,p[i].p->y);
    }
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(p[i].e<p[j].e){
                // swap
                Pair temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    printf("After sorting\n");
    for(int i=0;i<size;i++){
        printf("%d,(%d,%d)\n",p[i].e,p[i].p->x,p[i].p->y);
    }

}
void dfs(int x,int y,int a[][3],int visited[][3],int N,int M){
    visited[x][y]=1;
    // check bottom neighbour valid & !visited
    if(x+1<N && a[x][y]>=a[x+1][y] && !visited[x+1][y])
        dfs(x+1,y,a,visited,N,M);

    // check right neighbour valid & !visited
    if(y+1<M && a[x][y]>=a[x][y+1] && !visited[x][y+1])
        dfs(x,y+1,a,visited,N,M);

    // check above neighbour valid & !visited
    if(x-1>=0 && a[x][y]>=a[x-1][y] && !visited[x-1][y])
        dfs(x-1,y,a,visited,N,M);

    // check left neighbour valid & !visited
    if(y-1>=0 && a[x][y]>=a[x][y-1] && !visited[x][y-1])
        dfs(x,y-1,a,visited,N,M);
}
int minSources(int a[][3],int n,int m){
    int visited[n][m];
    // make pair array
    Pair adj[n*m];
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pair* p=(pair*)malloc(sizeof(pair));
            p->x=i;
            p->y=j;
            Pair pair;
            pair.e=a[i][j];
            pair.p=p;
            adj[c++]=pair;
        }
    }

    // sort based on Pair.e
    __sort(adj,n*m);

    // applying DFS on each vertex
    int count=0;
    for(int i=0;i<n*m;i++){
        if(!visited[adj[i].p->x][adj[i].p->y]){
            count++;
            printf("(%d,%d)\t",adj[i].p->x,adj[i].p->y);
            dfs(adj[i].p->x,adj[i].p->y,a,visited,n,m);
        }
    }
    return count;
}
int main(){
    int n=3,m=3;
    int a[][3]={{1,2,3},{2,3,1},{1,1,1}};
    printf("\nMinSources : %d\n",minSources(a,n,m));
}