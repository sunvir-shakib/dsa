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

    bool dfs(int src, int par, vector<bool> &vis){
        vis[src] = true;
        list<int> nbr = adjList[src];

        for(int u : nbr){
            if(!vis[u]){
                if(dfs(u, src, vis)){
                    return true;
                }
            }
            else{
                if(u != par){
                    return true; //cycle condition
                }
            }
        }
        return false;
    }

    bool isCycleUndir(int V){
        vector<bool> vis(V, false);
        return dfs(0, -1, vis);
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

    cout<<g.isCycleUndir(V)<<endl;

    return 0;
}
