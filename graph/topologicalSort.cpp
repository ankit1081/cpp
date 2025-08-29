#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

#define DIR true
#define UNDIR false
#define type float
#define DEFAULT_VERTICES 4

class Graph {
    int vertices; // Number of vertices
    vector<vector<pair<type, type>>> adjList; // Adjacency list
    vector<pair<type, type>> EdgeList; // Edge list

public:
    Graph(int vertex = DEFAULT_VERTICES) {
        vertices = vertex;
        adjList.resize(vertices);
    }

    void displayEdgeList() {
        cout << "\nEdge List: { ";
        for (auto pair_value : EdgeList)
            cout << "(" << pair_value.first << "," << pair_value.second << ")  ";
        cout << "}" << endl;
    }

    void addEdgeList(int one, int two) {
        pair<type, type> edge = {one, two};
        EdgeList.push_back(edge);
    }

    void displayAdjList() {
        cout << "\nAdjacency List:";
        for (int i = 0; i < vertices; i++) {
            cout << "\n" << i << ": ";
            for (auto pair_value : adjList[i])
                cout << "(" << pair_value.first << "," << pair_value.second << ")  ";
        }
        cout << endl;
    }

    void addEdges(int row, int column, bool direction = false, type weight = 1) {
        if (row >= vertices || row < 0 || column >= vertices || column < 0) {
            cout << "\nHamse na Ho Payega...Out of Bound";
            return;
        }

        pair<type, type> value = {column, weight};
        adjList[row].push_back(value);
        cout << "\n(" << value.first << "," << value.second << ") added to AdjList of " << row;

        if (!direction) {
            value = {row, weight};
            adjList[column].push_back(value);
            cout << "\n(" << value.first << "," << value.second << ") added to AdjList of " << column;
        }
    }

    void bfsTraversal(int src = 0) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        cout << "\n\nBFS Traversal: ";
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto neighbour : adjList[node]) {
                int val = neighbour.first;
                if (!visited[val]) {
                    q.push(val);
                    visited[val] = true;
                }
            }
        }

        // Handle disconnected components
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    cout << node << " ";
                    for (auto neighbour : adjList[node]) {
                        int val = neighbour.first;
                        if (!visited[val]) {
                            q.push(val);
                            visited[val] = true;
                        }
                    }
                }
            }
        }
    }

    void recursionDFS(int src, unordered_map<int, bool> &visited_map, stack<int> &topo) {
        visited_map[src] = true;

        for (auto neighbour : adjList[src]) {
            int node = neighbour.first;
            if (!visited_map[node]) {
                recursionDFS(node, visited_map, topo);
            }
        }

        topo.push(src); // Push after recursion for topological order
    }

    void dfsTraversal() {
        unordered_map<int, bool> visited_map;
        stack<int> topo;

        for (int src = 0; src < vertices; src++) {
            if (!visited_map[src]) {
                recursionDFS(src, visited_map, topo);
            }
        }

        cout << "\n\nTopological Sort (DFS Order): ";
        while (!topo.empty()) {
            cout << topo.top() << " ";
            topo.pop();
        }
        cout << endl;
    }
};

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    Graph G(6);

    G.displayEdgeList();
    G.addEdgeList(1, 2);
    G.displayEdgeList();

    G.addEdges(0, 1, DIR);
    G.addEdges(0, 2, DIR);
    G.addEdges(1, 3, DIR);
    G.addEdges(2, 4, DIR);
    G.addEdges(3, 5, DIR);
    G.addEdges(4, 5, DIR);

    G.displayAdjList();

    G.bfsTraversal();     // BFS
    G.dfsTraversal();     // DFS with Topological Sort

    return 0;
}

