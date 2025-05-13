#include <bits/stdc++.h>

using namespace std;

class Graph{
    private:
    int numberOfNodes;
    vector<vector<int>> adjlist;

    public:
    Graph(int numberOfNodes){
        this->numberOfNodes = numberOfNodes;
        adjlist.resize(numberOfNodes); // 0 base indexing
    }

    // Add Edge (Undirected)
    void addEdge(int u, int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u); // for Undirected graph only
    }

    // Removing edge technique 1
    void removeEdge_index_based(int u, int v){
        
        // Remove v from u's list
        for(int i=0; i< adjlist[u].size(); i++){
            if(adjlist[u][i] == v){
                adjlist[u].erase(adjlist[u].begin()+i);
                break;
            }
        }

        // Remove u from v's list
        for(int i=0; i< adjlist[v].size(); i++){
            if(adjlist[v][i] == u){
                adjlist[v].erase(adjlist[v].begin()+i);
                break;
            }
        }
    }

    // Removing edge technique 2
    void removeEdge_Iteration(int u, int v){

        // Remove v from u's List
        for(auto it=adjlist[u].begin(); it!=adjlist[u].end(); it++){
            if(*it == v){
                adjlist[u].erase(it);
                break;
            }
        }

        // Remove u from v's list
        for(auto it=adjlist[v].begin(); it!=adjlist[v].end(); it++){
            if(*it == u){
                adjlist[v].erase(it);
                break;
            }
        }
    }

    void printGraph(){
        cout<<"Adjacency List:"<<endl;
        for(int i=0; i<numberOfNodes; i++){
            cout<< i << "->";
            for(auto neighbor: adjlist[i]){
                cout<< neighbor <<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Before removing edge:\n";
    g.printGraph();

    g.removeEdge_Iteration(0, 2);

    cout << "\nAfter removing edge between 0 and 2:\n";
    g.printGraph();

    return 0;
}