#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    void dfs(int start, vector<int>adj[], int visited[], vector<int>&result){
        visited[start] = 1;
        result.push_back(start);
        
        // Traverse all its neighbours
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs(it, adj, visited, result);
            }
        }
    }
 
vector<int> dfsOfGraph(int v, vector<int>adj[]){
        int visited[v] = {0};
        int start = 0;
        vector<int> result;
        dfs(start, adj, visited, result);
        return result;
    }
};

int main()
{
    int v = 6;
    vector<int> adj[v];
    
    adj[0] = {1, 3};
    adj[1] = {0, 2, 3};
    adj[2] = {1, 3}; 
    adj[3] = {0, 1, 2, 4, 5};
    adj[4] = {3};
    adj[5] = {3}; 
    
    Graph g;
    vector<int> result = g.dfsOfGraph(v, adj);
    
    cout<<"DFS Traversal: ";
    for(int node: result){
        cout<< node <<" ";
    }
    cout<<endl;
    return 0;
}
