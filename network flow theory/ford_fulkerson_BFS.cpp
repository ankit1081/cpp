#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

struct Edge {
    int to;      // Target node
    int flow;    // Current flow
    int cap;     // Capacity
    int rev;     // Index of reverse edge
};

class Graph {
    int V;
    vector<vector<Edge>> adj;

    // BFS to find if there is a path from s to t
    bool bfs(int s, int t, vector<int>& parent, vector<int>& edgeIdx) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int i = 0; i < adj[u].size(); ++i) {
                Edge &e = adj[u][i];
                if (!visited[e.to] && e.flow < e.cap) {
                    parent[e.to] = u;
                    edgeIdx[e.to] = i;  // store which edge was used to reach e.to
                    visited[e.to] = true;
                    q.push(e.to);

                    if (e.to == t)
                        return true;
                }
            }
        }
        return false;
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int cap) {
        // Forward edge
        Edge forward = {v, 0, cap, (int)adj[v].size()};
        // Backward edge (residual)
        Edge backward = {u, 0, 0, (int)adj[u].size()};

        adj[u].push_back(forward);
        adj[v].push_back(backward);
    }

    int fordFulkersonWithBFS(int s, int t) {
        int max_flow = 0;
        vector<int> parent(V);
        vector<int> edgeIdx(V);

        while (bfs(s, t, parent, edgeIdx)) {
            int path_flow = INT_MAX;

            // Find the minimum capacity along the path
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                Edge &e = adj[u][edgeIdx[v]];
                path_flow = min(path_flow, e.cap - e.flow);
            }

            // Update the flow and the reverse edges
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                Edge &e = adj[u][edgeIdx[v]];
                e.flow += path_flow;
                adj[e.to][e.rev].flow -= path_flow;  // reverse flow
            }

            max_flow += path_flow;
        }

        return max_flow;
    }

    void display() {
        cout << "\nGraph Representation (Adjacency List with Capacities):\n";
        for (int u = 0; u < V; ++u) {
            cout << "Node " << u << ":\n";
            for (const Edge& e : adj[u]) {
                cout << "  --> " << e.to << " (cap: " << e.cap << ", revIdx: " << e.rev << ")\n";
            }
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(1, 2, 3);

    g.display();

    cout << "Maximum Flow: " << g.fordFulkersonWithBFS(0, 3) << endl;

    return 0;
}
