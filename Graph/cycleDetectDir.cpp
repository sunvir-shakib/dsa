#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int v;
    list<int> *adjList;

public:
    Graph(int v){
        this->v = v;
        adjList = new list<int>[v];
    }

    void addEdge(int u, int v, bool isDir){ 
        // isDir = false → undirected
        // isDir = true  → directed
        adjList[u].push_back(v);
        if(isDir == false){
            adjList[v].push_back(u);
        }
    }

    //-----
    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;

        for(int u : adjList[src]){
            if(!vis[u]){
                if(dirCycleHelper(u, vis, recPath)){ 
                    return true;
                }
            }
            else if(recPath[u]){  // already in recursion stack → cycle
                return true;
            }
        }

        recPath[src] = false;  // remove from recursion path
        return false;
    }

    bool isCycleDir(int V){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dirCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int V,E;
    cin>>V>>E;
    Graph g(V);

    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v,true);  // directed graph
    }
    
    cout<<g.isCycleDir(V)<<endl;

    return 0;
}
