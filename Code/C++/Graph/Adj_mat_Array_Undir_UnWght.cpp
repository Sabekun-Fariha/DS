#include <bits/stdc++.h>

using namespace std;

const int MAX = 100; // Maximum number of nodes

class Graph{
    public:
    int adjmat[MAX][MAX]; // Declaring adjacency matrix with 2D array
    int numberOfNodes;

    
    Graph(int numberOfNodes){
        this->numberOfNodes = numberOfNodes;
        // Initialize matrix with 0
        for(int i=0; i<numberOfNodes; i++){
           for(int j=0; j<numberOfNodes; j++){
            adjmat[i][j] = 0;
           }
        }
    }

    // Add Edge (undirected)
    void addEdge(int u, int v){
        if(u >= numberOfNodes || v >= numberOfNodes || u<0 || v<0){
            cout << "Invalid Node Index.\n";
            return;
        }
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
        cout<<"Edge added between "<<u<<" and "<<v<<".\n";
    }

    // Remove Edge
    void removeEdge(int u, int v){
        if(u >= numberOfNodes || v >= numberOfNodes || u<0 || v<0){
            cout << "Invalid Node Index.\n";
            return;
        }
        adjmat[u][v] = 0;
        adjmat[v][u] = 0;
        cout<<"Edge removed between "<<u<<" and "<<v<<". \n";
    }

    // Check if edge exists
    bool hasEdge(int u, int v){
        return adjmat[u][v] == 1;
    }

    // Print adjacency matrix
    void printMatrix(){
        cout<< "\nAdjacency Matrix: \n";
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
    Graph g(5); // Create graph with 5 nodes (0 to 4)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.printMatrix();

    cout<<"\nEdge between 1 and 3 ?"<<(g.hasEdge(1, 3)? " Yes":" No")<<endl;

    g.removeEdge(1,3);
    g.printMatrix();

    return 0;
}