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

    void addEdge(int u, int v){ //u--v
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool pathHelper(int src, int dest, vector<bool> &vis){
        if(src == dest){
            return true;
        }

        vis[src] = true;
        list<int> neighbours = adjList[src];
        for(int v : neighbours){
            if(!vis[v]){
                if(pathHelper(v, dest, vis)){
                    return true;
                }
            }
        }

        return false;
    }

    bool hashPath(int src, int dest){
        vector<bool> vis(v, false);
        return pathHelper(src, dest, vis);
    }
};

int main(){
    Graph graph(8); //undirected

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    
    cout<<graph.hashPath(1,3)<<endl;

    return 0;
}
