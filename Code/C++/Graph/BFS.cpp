#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    // BFS function
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};  // Visited array
        vis[0] = 1;
        queue<int> q;
        q.push(0);

        vector<int> bfs;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];

    // Add edges (undirected graph for example)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution obj;
    vector<int> bfs = obj.bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (int i : bfs) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
