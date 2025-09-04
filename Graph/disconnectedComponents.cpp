#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int> *adjList;

public:
    Graph(int v){
        this -> v = v;
        adjList = new list<int> [v];
    }
    
    void addEdge(int u, int v){ 
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void sortAdjList() {
    for (int i = 0; i < v; i++) {
        adjList[i].sort(); // sort each vertex’s neighbor list
    }
}


    //DFS ----
    void dfsHelper(int u, vector<bool> &vis){
        vis[u] = true;
        cout<< u << " ";

        list<int> neighbours = adjList[u];
        for(int v : neighbours){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }

    void dfs(int V){
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++){ //to visit all disconnected components
            if(!vis[i]){
                dfsHelper(i, vis); //starting from i
            }
        }
        cout<<endl;
        
    }
};

int main(){
    int V,E;
    cin>>V>>E;
    Graph g(V);

    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    g.sortAdjList();
    g.dfs(V);

    return 0;
}
