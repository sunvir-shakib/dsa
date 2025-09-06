#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge{
public:
    int u, v, wt;
    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph{
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;

    Graph(int V){ 
        this-> V = V; 
        for(int i=0; i<V; i++){ 
            par.push_back(i); 
            rank.push_back(0); 
        }
    }

    int find(int x){
        if(par[x] == x){
        return x;
        } 
        return par[x] = find(par[x]); // path compression
    }

    void unionByRank(int u, int v){
        if(rank[u] == rank[v]){
            par[v] = u;
            rank[u]++;
        }
        else if(rank[u] > rank[v]){
            par[v] = u;
        }
        else{
            par[u] = v;
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u,v,wt));
    }

    void kruskals(){
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});
        int minCost = 0, count = 0;

        for(auto &e : edges){
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV){
                unionByRank(parU, parV);
                minCost += e.wt;
                count++;
                if(count == V-1) 
                break;
            }
        }

        cout << "Min cost: " << minCost << endl;
    }
};

int main(){
    Graph graph(5);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);
    graph.addEdge(1,3,40);
    graph.addEdge(2,3,50);

    graph.kruskals();

    return 0;
}
