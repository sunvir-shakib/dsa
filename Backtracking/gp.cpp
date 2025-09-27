#include <bits/stdc++.h>
using namespace std;

class GRPCLR {
public:
    vector<vector<int>> graph;
    vector<int> color;
    int V, M;

    GRPCLR(int V, int M){
        this -> V = V;
        this -> M = M;

        graph.resize(V, vector<int>());
        color.resize(V, -1);

    }
    
    // Check if it's safe to color this node with color c
    bool isSafe(int src, int c) {
        for (int neighbor : graph[src]) {
            if (color[neighbor] == c) 
                return false; 
        }
        return true;
    }
    
    // Recursive backtracking 
    bool colorGraph(int src) {
        if (src == V) 
            return true;  
        
        for (int c = 0; c < M; c++) {
            if (isSafe(src, c)) {
                color[src] = c;
                if (colorGraph(src + 1)) 
                    return true;
                color[src] = -1;  // backtrack
            }
        }
        return false;
    }
    
    //
    bool canColor(int vertices, vector<vector<int>>& edges, int colors) {

        // Build adjacency list(undirected)
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]); 
            graph[e[1]].push_back(e[0]); 
        }
        
        return colorGraph(0); // start from node 0
    }
};

int main() {

    GRPCLR gc(4, 3);

    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    int M = 3;
    
       
    bool result = gc.canColor(V, edges, M);
    
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
