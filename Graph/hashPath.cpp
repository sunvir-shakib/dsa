#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int> *l;

public:
    Graph(int v){
        this -> v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v){ //u--v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0; u<v; u++){
            list<int> neighbours = l[u];
            cout<< u <<" : ";
            for(int v : neighbours){
                cout<<v << " ";
            }
            cout<<endl;
        }
    }

    void dfsHelper(int u, vector<bool> &vis){
        vis[u] = true;
        cout<< u << " ";

        list<int> neighbours = l[u];
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

    bool pathHelper(int src, int dest, vector<bool> &vis){
        if(src == dest){
            return true;
        }

        vis[src] = true;
        list<int> neighbours = l[src];
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
    Graph graph(7); //undirected

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    // graph.addEdge(5,6);
    
    cout<<graph.hashPath(5,6)<<endl;

    return 0;
}
