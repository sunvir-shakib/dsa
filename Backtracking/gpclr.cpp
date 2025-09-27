#include<iostream>
#include<vector>
#include<list>
using namespace std;

class GRPCLR{
public:
    vector<int> colour;
    vector<list<int>> graph;


    bool colourGraph(int N, int M, vector<int> &adjList, vector<int> &clrs){
        if(N == clrs.size()){
            return true;
        }

        for(int i = 0; i < M; i++){
            if()
        }

    }

    bool canColour(int V, vector<pair<int,int>> &edges, int M){

        vector<int> adjList[V];
        vector<int> clrs(V, -1);

        //create adj list
        for(auto &e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        return colourGraph(0, M, adjList,clrs ) ;

    }


};



int main() 
{
   int V, E , M;
   cin>>V>>E>>M;

   GRPCLR gp;

   vector<pair<int,int>> edges;
   for(int i=0; i<E; i++){
    int u, v;
    cin>>u>>v;
    edges.push_back({u,v});
   }

   gp.canColour(V, edges, M);
   
    return 0;
}
