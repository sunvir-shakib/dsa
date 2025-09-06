#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> *adjList; // (neighbor, weight)

public:
    Graph(int v){
        this -> v = v;
        adjList = new list<pair<int,int>> [v];
    }
    //adj List
    void addEdge(int u, int v, int wt){ 
        adjList[u].push_back(make_pair(v, wt));
        adjList[v].push_back(make_pair(u, wt));
    }

    void primsAlgo(int src){
        vector<bool> mst(v, false);
        priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //(wt , v) -> minHeap 

        pq.push(make_pair(0, src));
        int ans = 0;

        while(!pq.empty()){
            int wt = pq.top().first;
            int v = pq.top().second;
            pq.pop();

            if(!mst[v]){
                mst[v]= true;
                ans+= wt;

                for(auto n : adjList[v]){
                    int u = n.first;       // neighbor
                    int currWt = n.second; // weight
                    pq.push(make_pair(currWt, u));
                }
            }
        }
        cout<<"final cost: "<<ans<<endl;
    }
};

int main(){
    Graph graph(4); //undirected

    graph.addEdge(0,1, 10);
    graph.addEdge(0,2, 15);
    graph.addEdge(0,3, 30);
    graph.addEdge(1,3, 40);
    graph.addEdge(2,3, 50);

    graph.primsAlgo(0);

    return 0;
}
