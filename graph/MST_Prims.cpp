#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pi;  // {vertex, weight}

class Edge {
public:
    int dest, weight;
    Edge(int d, int w) : dest(d), weight(w) {}
};

class Graph {
private:
    int V;
    vector<vector<Edge>> adjList;  // Use vector of Edge objects

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdges(int u, int v, int w) {
        adjList[u].push_back(Edge(v, w));
        adjList[v].push_back(Edge(u, w));
    }

    void primMST() {
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        vector<int> key(V, INT_MAX);//key means cost of node
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);

        key[0] = 0;
        pq.push({0, 0});  // {cost, vertex}

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (Edge &e : adjList[u]) {
                int v = e.dest, w = e.weight;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        // Print MST
        cout << "Prim's MST:\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
        }

        //final cost
        int cost = 0;
        for(int i = 1; i<V; i++){
            cost = cost + key[i];
        }
        cout<<"Final cost : "<<cost;
    }
};

int main() {
    Graph g(4);
    g.addEdges(0, 1, 1);
    g.addEdges(0, 2, 3);
    g.addEdges(1, 2, 5);
    g.addEdges(1, 3, 2);
    g.addEdges(2, 3, 4);

    g.primMST();
    return 0;
}
