#include<iostream>
#include<vector>
#include<algorithm> //for sort fun
using namespace std;

class Graph{
public:
    int V;
    vector<pair<int, pair<int,int>>> edges; //{w, u, v}
    vector<int> par;
    vector<int> rank;
    
    Graph(int V){
        this->V = V;
        par.resize(V);
        rank.resize(V);
        
        for(int i=0; i<V; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]); // Path compression
    }
    
    void unionByRank(int parU, int parV){
        
        if(rank[parU] > rank[parV]){
            par[parV] = parU;
        }

        else if(rank[parU] < rank[parV]){
            par[parU] = parV;
        }

        else{
            par[parV] = parU;
            rank[parU]++;
        }
    }
    
    void kruskal(){
        sort(edges.begin(), edges.end()); // 3rd: Sort by weight
        int minCost = 0;
        
        for(int i=0; i<edges.size(); i++){
            int w = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            
            int parU = find(u); // 4th: Find parents
            int parV = find(v);
            
            if(parU != parV){
                unionByRank(parU, parV); // 5th: Union
                minCost += w;
            }
        }
        cout<<minCost<<endl;
    }
    
    void addEdge(int w, int u, int v){
        edges.push_back({w, {u,v}});
    }
};

int main()
{
    int V,E;
    cin>>V>>E;
    
    Graph g(V);
    
    for(int i=0; i<E; i++){
        int w, u, v;
        cin>>w>>u>>v;
        g.addEdge(w, u, v); // 1st: Add edges
    }
    
    g.kruskal(); // 2nd: Run algorithm
    
    return 0;
}