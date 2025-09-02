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

    //BFS
    void bfs() {
        queue<int> q;
        vector<bool> vis(v, false);
        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            int u = q.front(); // curr vertex
            q.pop();
            cout << u << " ";

            for(int nbr : l[u]) {
                if(!vis[nbr]) {
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        cout << endl;
    }

};


int main(){
    Graph graph(5); //undirected

    graph.addEdge(0,3);
    graph.addEdge(3,1);
    graph.addEdge(1,4);
    graph.addEdge(1, 2);

    graph.bfs();


    return 0;
}
