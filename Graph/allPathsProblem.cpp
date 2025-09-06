#include<iostream>
#include<vector>
#include<string>
#include<list>
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
        adjList[u].push_back(v); //directed graph
    }

    void pathHelper(int src, int des, vector<bool> &vis, string &path ){
        if(src == des){
            cout << path << des << endl; // print final path
            return;
        }

        vis[src] = true;
        path += to_string(src);   // only keep this (removed push_back)

        for(int v : adjList[src]){
            if(!vis[v]){
                pathHelper(v, des, vis, path);
            }
        }

        path = path.substr(0, path.size() - to_string(src).size()); //issues
        vis[src] = false;
    }

    void printAllHashPaths(int src, int des, int V){
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, des, vis, path);
    }

};

int main(){
    int V,E;
    cin >> V >> E;
    Graph g(V);

    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v);
    }

    int src,des;
    cin >> src >> des;
    g.printAllHashPaths(src, des, V);

    return 0;
}
