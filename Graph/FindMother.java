/**
 * Find Mother node of a graph
 * @author TheAndroCoder
 */
import java.util.*;
 public class FindMother{
     public static void DFSUtil(Graph g,int s,boolean[] visited){
         visited[s]=true;
         
         for(int i=0;i<g.adj[s].size();i++){
             int v=g.adj[s].get(i);
             if(!visited[v]){
                 DFSUtil(g,v,visited);
             }
         }
     }
     public static int motherVertex(Graph g){
         boolean visited[]=new boolean[g.v];
         int v=-1; // for tracking last visited vertex, the last visited vertex is the mother vertex
         
         for(int i=0;i<g.v;i++){
             if(!visited[i]){
                 DFSUtil(g,i,visited);
                 v=i;
             }
         }

         //check if all vertices can be visited from v
         Arrays.fill(visited,false);

         DFSUtil(g,v,visited);

         for(int i=0;i<g.v;i++){
             if(!visited[i])return -1;
         }
         return v;
     }
     public static void main(String[] args){
         Graph g = new Graph(7);
         g.addEdge(0,1);
         g.addEdge(0,2);
         g.addEdge(1,3);
         g.addEdge(4,1);
         g.addEdge(6,4);
         g.addEdge(5,6);
         g.addEdge(5,2);
         g.addEdge(6,0);

         System.out.println("Mother Vertex : "+motherVertex(g));
     }
 }