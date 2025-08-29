#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int vertex;//number of vertices
    bool directed;
    vector<vector<pair<int,int>>> adjList; //pair to store {neighbour,weights} for node

public:
    //making a constructor
    Graph(int vertex, bool isDirected = false){
        this->vertex = vertex;
        this->directed = isDirected;
        adjList.resize(vertex);
    }
    //creating a funtion to make a graph where default weight will be 1 if graph is not weighted
    void addEdge(int u , int v, int w =1){
        adjList[u].push_back({v,w});
        //for undirected
        if (!directed){
            adjList[v].push_back({u,w});
        }
    }

    void displayAdjList(){
        cout<<"\nAdjacency List :\n";
        for(int i =0 ; i<vertex; i++){
            cout<<i<<"->";
            //displaying neighbour and weights of each node
            for (auto p : adjList[i]) {
                int nbr = p.first;
                int w = p.second;
                cout << "(" << nbr << "," << w << ")";
            }

        }
    }

    //bfs code starting from src
    //making return type as vector to furthur use and increse modularity of code
    vector<int>bfs (int start){
        //making a vecttor to store visited nodes
        vector<bool> visited(vertex,false);
        //making queue to process nodes
        queue<int> q;
        //making vector to store results
        vector<int> result;
        //marking start as visited and pushing the start node into queue
        visited[start] = true;
        q.push(start);
        //creating loop to process all nodes
        while(!q.empty()){
            //taking current node and pushing into result
            int current  = q.front();
            q.pop();
            result.push_back(current);

            //making case to process nbr nodes of current
            
                
            for (auto p : adjList[current]) {
                //if visited == false , then mark visited and push into queue
                int nbr = p.first;
                int w = p.second;    
                if(!visited[nbr]){
                    visited[nbr]= true;
                    q.push(nbr);
                }
            }
        }

        //code for disconnectred nodes
        for (int i = 0; i < vertex; i++) {
            if (!visited[i]) {

                visited[i] = true;
                q.push(i);

                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    result.push_back(current);

                    for (auto p : adjList[current]) {
                        int nbr = p.first;
                        int w = p.second;
                        if (!visited[nbr]) {
                            visited[nbr] = true;
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        return result;

    }

    //making a dfs helper code, this is based on recurion logic because dfs goes inside each node which is called recursively
    void dfsHelper(int current,vector<bool> &visited, vector<int> &result){
        visited[current] = true;
        result.push_back(current);

        for (auto p : adjList[current]){
            int nbr = p.first;
            int w = p.second;
            if (!visited[nbr]){
                dfsHelper(nbr,visited, result);
            }
        }

    }

    //making real dfs code
    vector<int>dfs(int start){
        vector<bool>visited(vertex, false);
        vector<int> result;

        //dfs from the start node
        if(!visited[start]){
            dfsHelper(start,visited,result);
        }

        //dfs for disconnected parts
        for(int i= 0; i<vertex ; i++){
            if(!visited[i]){
                dfsHelper(i,visited,result);
            }
        }
        return result;
    }


};

int main() {
    Graph g(6); // undirected by default

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4); // disconnected component
    g.addEdge(4, 5);

    g.displayAdjList();

    vector<int> traversal1 = g.bfs(0);

    cout << "\nBFS Traversal (including disconnected): ";
    for (int node : traversal1) {
        cout << node << " ";
    }

    vector<int> traversal2 = g.dfs(0);

    cout << "\nDFS Traversal (including disconnected): ";
    for (int node : traversal2) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

