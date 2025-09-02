#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> AdjList; // adjacency list
    unordered_map<int, bool> visited;      // visited tracker

    // Prepare adjacency list from edge list
    void prepareAdjList(vector<pair<int,int>>& edges) {
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            AdjList[u].push_back(v);
            AdjList[v].push_back(u); // undirected
        }
    }

    // BFS function
    void bfs(int node, vector<int>& ans) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto i : AdjList[frontNode]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    // Traverse all components
    vector<int> BFS(int vertex, vector<pair<int,int>> edges) {
        vector<int> ans;
        prepareAdjList(edges);

        for(int i = 0; i < vertex; i++) {
            if(!visited[i]) {
                bfs(i, ans);
            }
        }

        return ans;
    }
};

int main() {
    Graph g;

    int vertex = 5;
    vector<pair<int,int>> edges = {
        {0,1}, {0,2}, {1,3}, {2,4}
    };

    vector<int> result = g.BFS(vertex, edges);

    cout << "BFS Traversal: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
