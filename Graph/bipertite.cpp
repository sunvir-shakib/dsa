#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int v;     
    list<int>* adjList;    // adjacency list (array of lists)

public:

    Graph(int v) {
        this->v = v;
        adjList = new list<int>[v]; // create an array of lists
    }

   
    void addEdge(int u, int v) {
        adjList[u].push_back(v); 
        adjList[v].push_back(u); 
    }

    bool isBipertite(int v){
    queue<int> q;
    // vector<bool> vis(v, false);
    vector<int> clr(v, -1); // for coloring graph

    q.push(0);
    // vis[0] = true;
    clr[0] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int u: adjList[curr]){
            if(clr[u] == -1){
                // vis[u] = true;
                clr[u] = !clr[curr];  //set to opposite clr
                q.push(u);
            }
            else{
                if(clr[u] == clr[curr]){
                    return false;
                }
            }
        }
    }
    return true;
}

};

int main() {
    int v, e;
    cin >> v >> e;  

    Graph graph(v);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v); 
    }

    cout<<graph.isBipertite(v)<<endl;


    return 0;
}
