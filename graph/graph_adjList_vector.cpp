#include<iostream>
#include<vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices);
    }

    // Add edge
    void addEdge(int u, int v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir)
            adjList[v].push_back(u);
    }

    // Print adjacency list using auto
    void printGraph() {
    for (int i = 0; i < vertices; i++) {
        cout << i << " --> ";
        for (auto neighbour : adjList[i]) {
            cout << neighbour << " ";
        }
        cout << endl;
    }
}

};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Graph :\n";
    g.printGraph();

    return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices);
    }

    // Add edge
    void addEdge(int u, int v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir)
            adjList[v].push_back(u);
    }

    // Print adjacency list
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " --> ";
            for (int neighbour : adjList[i]) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Graph (Adjacency List):\n";
    g.printGraph();

    return 0;
}




#include<iostream>
#include<vector>
#include<list>
using namespace std;
 class graph{

 public:
     vector<vector<int>> adj;

     void addEdge(int u , int v, bool direction){
     // direction = 0 = undirected
     // direction = 1 = directed
     // create an edge from u to v
     adj[u].push_back(v);

     if(direction ==0){
        adj[v].push_back(u);
     }
    }
    void print(){
        for(auto i :adj){
            cout<<i.first<<"->";
            for(auto j :i.second){
                cout<<j<<",";
            }
            cout<<endl;

        }
    }
 };
 int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    int m ;
    cout<<"Enter the number of edges : ";
    cin>>m;

    graph g;
    for(int i =0 ; i<m;i++){
        int u, v;
        cout<<"Enter the relation :";
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.print();
 }

*/
