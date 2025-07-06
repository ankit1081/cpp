#include<iostream>
#include<vector>
#inlcude<queue>
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
