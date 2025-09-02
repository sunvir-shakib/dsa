#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int v;
    list<pair<int, int>> *l; // pair<destination, weight>

public:
    Graph(int v){
        this -> v = v;
        l = new list<pair<int, int>>[v];
    }

    void addEdge(int u, int v, int weight) {
        l[u].push_back({v, weight});
        l[v].push_back({u, weight}); 
    }


    void print() {
        for(int u = 0; u < v; u++) {
            cout << u << " : ";
            for(auto edge : l[u]) {
                cout << "(" << edge.first << "," << edge.second << ") ";
            }
            cout << endl;
        }
    }
};


int main(){
    Graph graph(5); //undirected

    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 15);
    graph.addEdge(1, 3, 20);
    graph.addEdge(2, 3, 25);
    graph.addEdge(2, 4, 30);

    graph.print();

    return 0;
}
