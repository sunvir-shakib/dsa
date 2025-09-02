#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
template<typename T>

class Graph{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        //direction 0 = undirected
        //direction 1 = directed

        //crate an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void prTList(){
        for(auto i : adj){
            cout<<i.first <<" -> ";
            for(auto j : i.second){
                cout<< j<< ", ";
            }
            cout<<endl;
        }
    }
};

int main() 
{
    Graph<int> graph;

    int  n;  //num of nodes
    cin>>n;

    for(int i=0; i<n; i++){
        int u, v;
        cin>> u >> v;
        graph.addEdge(u, v, 0);
    }

    graph.prTList();
   
   
    return 0;
}
