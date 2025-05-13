#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    vector<vector<int>> adjmat;
    int numberOfNodes;

    Graph(int numberOfNodes){
        this->numberOfNodes = numberOfNodes;
        adjmat.resize(numberOfNodes, vector<int>(numberOfNodes, 0));
        // Initialize matrix with 0
        // for(int i=0; i<numberOfNodes; i++){
        //     for(int j=0; j<numberOfNodes; j++){
        //         adjmat[i][j] = 0;
        //     }
        //  }
    }

    // Add edge (undirected)
    void addEdge(int u, int v){
        if (u >= numberOfNodes || v >= numberOfNodes || u < 0 || v < 0) {
            cout << "Invalid node index.\n";
            return;
        }
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
        cout << "Edge added between " << u << " and " << v << ".\n";

    }

    // Remove edge
    void removeEdge(int u, int v){
        if (u >= numberOfNodes || v >= numberOfNodes || u < 0 || v < 0) {
            cout << "Invalid node index.\n";
            return;
        }
        adjmat[u][v] = 0;
        adjmat[v][u] = 0;
        cout << "Edge removed between " << u << " and " << v << ".\n";
   
    }

    // Check if edge exists
    bool hasEdge(int u, int v){
        return adjmat[u][v] == 1;
    }

    // Print adjacency matrix
    void printGraph(){
        cout<<"\nGraph with Adjacency Matrix:\n";
        for(int i=0; i<numberOfNodes; i++){
            for(int j=0; j<numberOfNodes; j++){
                cout<<adjmat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(5); // Graph with 5 nodes: 0 to 4
    g.printGraph();

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.printGraph();

    cout << "\nEdge between 1 and 3? " << (g.hasEdge(1, 3) ? "Yes" : "No") << endl;

    g.removeEdge(1, 3);
    g.printGraph();
}