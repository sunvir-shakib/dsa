#include <bits/stdc++.h>
using namespace std;

class GraphColoring1 {

    vector<vector<int>> graph;
    vector<int> color;
    int n, m;
    
    bool isSafe(int v, int c) {
        for (int neighbor : graph[v]) {
            if (color[neighbor] == c) 
                return false;
        }
        return true;
    }
    
    bool solve(int v) {
        if (v == n) return true;  // All vertices colored
        
        for (int c = 0; c < m; c++) {
            if (isSafe(v, c)) {
                color[v] = c;
                if (solve(v + 1)) return true;
                color[v] = -1;  // backtrack
            }
        }
        return false;
    }
    

    
    bool canColor(int vertices, vector<pair<int,int>>& edges, int colors) {
        n = vertices;
        m = colors;
        graph.assign(n, vector<int>());
        color.assign(n, -1);
        

        for (auto& edge : edges) {
            int u = edge.first;   // First vertex of the edge
            int v = edge.second;  // Second vertex of the edge
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        return solve(0);
    }
};

int main() {
    int V = 4;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    int m = 3;
    
    GraphColoring1 gc;
    cout << (gc.canColor(V, edges, m) ? "true" : "false") << endl;
    
    return 0;
}