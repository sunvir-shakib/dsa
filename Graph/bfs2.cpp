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


    void bfs(int src) {
        queue<int> q;             // queue for BFS
        vector<bool> vis(v, false); // visited array (size = v)

        q.push(src);   // start BFS from src
        vis[src] = true; // mark source as visited

        while (!q.empty()) {
            int u = q.front(); // get current node
            q.pop();
            cout << u << " ";  // print current node

            // Explore all neighbors of u
            for (int nbr : adjList[u]) {
                if (!vis[nbr]) {       // if neighbor not visited
                    vis[nbr] = true;   // mark visited
                    q.push(nbr);       // add neighbor to queue
                }
            }
        }
        cout << endl;
    }

    //to print list
    void printList(){
    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        for (int nbr : adjList[i]) {
            cout << nbr << " ";
        }
        cout << endl;
    }
}
};

int main() {
    int v, e;
    cin >> v >> e;  // input number of vertices and edges

    Graph graph(v);

    // Input all edges
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v); // add edge between u and v
    }

    graph.printList(); //print list

    int src;
    cin >> src; // input starting node for BFS

    graph.bfs(src); 

    return 0;
}
