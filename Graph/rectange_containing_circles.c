/**
 * Rectangle containing circles
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct pair{
    int x,y;
}pair;
//** Queue Implementation with pair dtype **//
int rear=-1;
int front=-1;
pair p_arr[100];
void enqueue(pair p){
    p_arr[++rear]=p;
}
int isEmpty(){
    return front==rear;
}
pair dequeue(){
    if(!isEmpty()){
        return p_arr[++front];
    }
    pair p;
    p.x=0;
    p.y=0;
    return p;
}

pair peek(){
    return p_arr[front];
}
// ****************************** //
int isPossible(int n,int m,pair p[],int k,int r){
    int visited[n][m];
    // mark as visited for the ones which have circle passing
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            visited[i][j]=0;
            for(int s=0;s<k;s++){
                int x=p[s].x;
                int y=p[s].y;
                // see if i,j lies within this circle with centre x,y
                if(sqrt(pow(x-i,2)+pow(y-j,2))<=r){
                    visited[i][j]=1;
                    printf("Blocked (%d,%d)\n",i,j);
                }
            }
        }
    }

    // try BFS here
    printf("visited[1][1]=%d\n",visited[1][1]);
    if(visited[1][1]==1)return 0;

    pair pp;
    pp.x=1;
    pp.y=1;
    enqueue(pp);
    visited[1][1]=1;
    while(!isEmpty()){
        pp=dequeue();
        int elex=pp.x;
        int eley=pp.y;
        printf("pp.x,pp.y=%d,%d\n",elex,eley);
        // discover all adjacent 8 boxes
        // visiting top left
        if(elex-1>0 && eley-1>0 && !visited[elex-1][eley-1]){
            visited[elex-1][eley-1]=1;
            pair pa;
            pa.x=elex-1;
            pa.y=eley-1;
            enqueue(pa);
        }
        // visiting top
        if(elex-1>0 && !visited[elex-1][eley]){
            visited[elex-1][eley]=1;
            pair pa;
            pa.x=elex-1;
            pa.y=eley;
            enqueue(pa);
        }
        // visiting top right
        if(elex-1>0 && eley+1<n && !visited[elex-1][eley+1]){
            visited[elex-1][eley+1]=1;
            pair pa;
            pa.x=elex-1;
            pa.y=eley+1;
            enqueue(pa);
        }
        // visiting right
        if(eley+1<n && !visited[elex][eley+1]){
            visited[elex][eley+1]=1;
            pair pa;
            pa.x=elex;
            pa.y=eley+1;
            enqueue(pa);
        }
        // visiting bottom right
        if(elex+1<n && eley+1<n && !visited[elex+1][eley+1]){
            visited[elex+1][eley+1]=1;
            pair pa;
            pa.x=elex+1;
            pa.y=eley+1;
            enqueue(pa);
        }
        // visited bottom
        if(elex+1<n && !visited[elex+1][eley]){
            visited[elex+1][eley]=1;
            pair pa;
            pa.x=elex+1;
            pa.y=eley;
            enqueue(pa);
        }
        // visited bottom left
        if(elex+1<n && eley-1>0 && !visited[elex+1][eley-1]){
            visited[elex+1][eley-1]=1;
            pair pa;
            pa.x=elex+1;
            pa.y=eley-1;
            enqueue(pa);
        }
        // visiting left
        if(eley-1>0 && !visited[elex][eley-1]){
            visited[elex][eley-1]=1;
            pair pa;
            pa.x=elex;
            pa.y=eley-1;
            enqueue(pa);
        }
    }

    return visited[n-1][m-1];
}

int main(){
    int N=5,M=5;
    int k=1,r=1;
    pair p[k];
    pair *p1=(pair*)malloc(sizeof(pair));
    p1->x=1;
    p1->y=3;
    p[0]=*p1;
    // pair *p2=(pair*)malloc(sizeof(pair));
    // p2->x=1;
    // p2->y=3;
    // p[1]=*p2;
    // (1,2),(1,3)
    if(isPossible(N+1,M+1,p,k,r)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}