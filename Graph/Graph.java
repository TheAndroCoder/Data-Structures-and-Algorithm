/**
 * Graph Class
 * @author TheAndroCoder
 */
import java.util.*;
public class Graph{
    int v;
    List<Integer> adj[];
    public Graph(int v){
        this.v=v;
        adj=new LinkedList[v];
        for(int i=0;i<v;i++)adj[i]=new LinkedList();
    }

    void addEdge(int u,int v){
        adj[u].add(v);
    }
    void BFS(int s){
        boolean visited[]= new boolean[v];
        Queue<Integer> q =new LinkedList<>();
        visited[s]=true;
        q.add(s);
        while(q.size()!=0){
            s=q.poll();
            System.out.print(s+" ");

            Iterator<Integer> it = adj[s].listIterator();
            while(it.hasNext()){
                int n=it.next();
                if(!visited[n]){
                    visited[n]=true;
                    q.add(n);
                }
            }
        }
    }
}