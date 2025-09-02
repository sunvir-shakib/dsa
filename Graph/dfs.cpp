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

    void dfs(){
        vector<bool> vis(7, false);
        dfsHelper(0, vis);
    }
};

int main(){
    Graph graph(7); //undirected

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    
    graph.dfs();

    return 0;
}
