/**
 * Kruskals minimum spanning tree
 * @author TheAndroCoder
 * */

#include<stdio.h>
#include<stdlib.h>
typedef struct subset{
    int parent,rank;
}subset;
typedef struct Edge{
    int src,dest,weight;
}Edge;
typedef struct Graph{
    int V,E;
    Edge* edge;
}Graph;
Graph* createGraph(int v,int e){
    Graph* graph=(Graph*)malloc(sizeof(Graph));
    graph->V=v;
    graph->E=e;
    graph->edge=(Edge*)malloc(sizeof(Edge));
    return graph;
}
int myComp(const void* a,const void* b){
    Edge* a1=(Edge*)a;
    Edge* b1=(Edge*)b;
    return a1->weight>b1->weight;
}
int find(subset* s,int i){
    if(s[i].parent!=i){
        s[i].parent=find(s,s[i].parent);
    }
    return s[i].parent;
}
void Union(subset s[],int x,int y){
    int xroot=find(s,xroot);
    int yroot = find(s,yroot);

    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (s[xroot].rank < s[yroot].rank)
        s[xroot].parent = yroot;
    else if (s[xroot].rank > s[yroot].rank)
        s[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and
    // increment its rank by one
    else
    {
        s[yroot].parent = xroot;
        s[xroot].rank++;
    }
}
void kruskalMST(Graph* graph){
    int v=graph->V;
    Edge result[v];
    int e=0;
    qsort(graph->edge,graph->E,sizeof(graph->edge[0]),myComp);
    // subset* subsets=(subset*)malloc(v*sizeof(subset));
    subset subsets[v];
    for(int i=0;i<v;i++){
        subsets[v].parent=v;
        subsets[v].rank=0;
    }
    int i=0;
    while(e<v-1 && i<graph->E){
        Edge next_edge = graph->edge[i++];
        int x=find(subsets,next_edge.src);
        int y=find(subsets,next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printf(
        "Following are the edges in the constructed MST\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src,
            result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning tree : %d",minimumCost);
}
int main(){
    int v=4;
    int e=5;
    Graph* graph=createGraph(v,e);
     // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
    kruskalMST(graph);
    return 0;
}