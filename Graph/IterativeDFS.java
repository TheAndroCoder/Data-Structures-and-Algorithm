/**
 * Iterative DFS
 * @author TheAndroCoder
 */
import java.util.*;
public class IterativeDFS{
    public static void main(String... args){
        Graph g = new Graph(5);
        g.addEdge(1,0);
        g.addEdge(0,2);
        g.addEdge(2,1);
        g.addEdge(0,3);
        g.addEdge(1,4);

        DFS(g,0); // taking 0 as starting node
    }

    static void DFS(Graph g,int v){
        boolean visited[]=new boolean[g.v];
        Stack<Integer> st = new Stack<>();
        st.push(v);

        while(!st.empty()){
            v=st.pop();

            if(!visited[v]){
                System.out.print(v+" ");
                visited[v]=true;
            }

            Iterator<Integer> it = g.adj[v].iterator();
            while(it.hasNext()){
                v=it.next();
                if(!visited[v])st.push(v);
            }
        }

    }
}