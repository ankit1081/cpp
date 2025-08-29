#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;


struct Edge{
    int to;
    int capacity;
    int rev;//index of reverse edge im adj[to]
};
class Graph{
    int v;
    vector<vector<Edge>> adj;

    bool dfs(int u ,int t , vector < bool>&visited , vector<int>&parent){
        stack<int> st;
        st.push(u);
        visited[u] = true;
        parent[u] = -1;

        while (!st.empty()) {
            int curr = st.top(); st.pop();

            for (int i = 0; i < adj[curr].size(); ++i) {
                Edge &e = adj[curr][i];
                if (!visited[e.to] && e.capacity > 0) {
                    visited[e.to] = true;
                    parent[e.to] = curr;
                    if (e.to == t)
                        return true;
                    st.push(e.to);
                }
            }
        }
        return false;
    }
public:
    Graph(int V){
        this->v =V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int cap){
        //forward edge
        Edge forward = {v, cap, (int)adj[v].size()};
        //backward edge for residual graph
        Edge backward = {u, 0, (int)adj[u].size()};

        adj[u].push_back(forward);
        adj[v].push_back(backward);
    }

    int fordFulkersonWithDFS(int s, int t) {
        int max_flow = 0;
        vector<int> parent(v); // not really used here, can be removed
        vector<bool> visited(v);

        while (true) {
            fill(visited.begin(), visited.end(), false);
            vector<int> path(v, -1); // to store parent of each node
            stack<int> st;
            st.push(s);
            visited[s] = true;

            while (!st.empty()) {
                int u = st.top(); st.pop();

                for (int i = 0; i < adj[u].size(); ++i) {
                    Edge &e = adj[u][i];
                    if (!visited[e.to] && e.capacity > 0) {
                        visited[e.to] = true;
                        path[e.to] = u; // parent of v is u
                        if (e.to == t) break; // path found
                        st.push(e.to);
                    }
                }
            }

            if (!visited[t]) break; // no more augmenting path

            // Find minimum residual capacity in the path
            int path_flow = INT_MAX;
            for (int vtx = t; vtx != s; vtx = path[vtx]) {
                int u = path[vtx];
                for (Edge &e : adj[u]) {
                    if (e.to == vtx && e.capacity > 0) {
                        path_flow = min(path_flow, e.capacity);
                        break;
                    }
                }
            }

            // Update capacities (forward and reverse edges)
            for (int vtx = t; vtx != s; vtx = path[vtx]) {
                int u = path[vtx];
                for (Edge &e : adj[u]) {
                    if (e.to == vtx) {
                        e.capacity -= path_flow;
                        adj[vtx][e.rev].capacity += path_flow;
                        break;
                    }
                }
            }

            max_flow += path_flow;
        }

        return max_flow;
    }

    void display() {
        cout << "\nGraph Representation (Adjacency List with Capacities):\n";
        for (int u = 0; u < v; ++u) {
            cout << "Node " << u << ":\n";
            for (const Edge& e : adj[u]) {
                cout << "  --> " << e.to << " (cap: " << e.capacity << ", revIdx: " << e.rev << ")\n";
            }
        }
    }


};



int main()
{
    Graph g(4);

    g.addEdge(0,1,10);
    g.addEdge(0,2,5);
    g.addEdge(1,3,8);
    g.addEdge(2,3,7);
    g.addEdge(1,2,3);

    g.display();

    cout<<"Maximum Flow :"<< g.fordFulkersonWithDFS(0,3)<<endl;

    return 0;
}
