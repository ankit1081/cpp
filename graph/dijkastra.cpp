#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<climits>
#include<unordered_map>
using namespace std;

#define DIR true
#define UNDIR false
#define type float
#define default 4

class Graph{
    int vertices; //no of vertices
    vector<vector<pair<type,type>>> adjList;
    vector<pair<type, type>> EdgeList;

public:
    Graph(int vertex=default)
    {
        vertices=vertex;
        adjList.resize(vertices);
    }

    void dijkastra(int src){
        if(src>=vertices|| src<0){
            cout<<"out of bound ";
        }

        vector<int>distance({vertices,INT_MAX});
        set<pair<int,int>> st;

        distance[src]=0;
        st.insert({distance[src],src});

        while(!st.empty()){
            auto set_minimum_vertex_pair= *(st.begin());
            int set_minimum_weight = set_minimum_vertex_pair.first;
            int set_minimum_weight_vertex = set_minimum_vertex_pair.second;

            st.erase(st.begin());

            for(auto nbr:adjList[set_minimum_weight_vertex]){
                int nbrNode = nbr.first;
                int nbrDistance = nbr.second;

                if (distance[set_minimum_weight_vertex]+nbrDistance<distance[nbrNode]){
                    distance[nbrNode]=distance[set_minimum_weight_vertex]+nbrDistance;

                    auto it = st.find({distance[nbrNode],nbrNode});
                    if(it != st.end()){
                        st.erase(it);
                    }
                }
            }
        }
        cout << "\nDijkstra (using set) from node " << src << ":\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "Node " << i << ": Distance = ";
            if (distance[i] == INT_MAX)
                cout << "INF";
            else
                cout << distance[i];
            cout << endl;
    }
    }
    void displayEdgeList()
    {
        cout<<endl<<"{";
        for (auto pair_value: EdgeList)
                cout<<"("<<pair_value.first<<","<<pair_value.second<<")  ";

        cout<<"}"<<endl;
    }

    void addEdgeList(int one, int two)
    {
        pair<type, type> edge={one, two};
        EdgeList.push_back(edge);
    }

    void displayAdjList()
    {
        cout<<endl<<"AdjList Vector of Vector"<<endl;

        for (int i=0;i<vertices;i++)
        {
            cout<<endl<<i<<":";
            for (auto pair_value: adjList[i])
                cout<<"("<<pair_value.first<<","<<pair_value.second<<")  ";
        }
    }

    void addEdges(int row, int column, bool direction=false, type weight =1) //by default undirected
    {
        if (row>=vertices || row<0 || column>= vertices || column<0)
            cout<<"\nHamse na Ho Payega...Out of Bond";

    pair<type,type> value={column,weight};
    adjList[row].push_back(value);
    cout<<endl<<value.first<<" & "<<value.second<<" is pushed into AdjList of "<<row;


    if (!direction) // by default un directed
    {
        value={row, weight};
        adjList[column].push_back(value);
        cout<<endl<<value.first<<" & "<<value.second<<" is pushed into AdjList of "<<column;
    }
    }

    void bfsTraversal(int src=0)
    {
        queue<int> q;
        unordered_map<int, bool> visited_map;
        cout<<endl;

        q.push(src);
        visited_map[src]=true;

        while(!q.empty())
        {
            int Node=q.front();
            cout<<Node<<" ";
            q.pop();

            for(auto neighbour : adjList[Node])
            {
                int val=neighbour.first;
                if (!visited_map[val])
                {
                    q.push(val);
                    visited_map[val]=true;
                }
            }


        }

        for (int i=0;i<vertices;i++) //this loop is for dis-connected graphs onlyyyyyyyy this will display left over elements

            if (!visited_map[i])
                cout<<i<<" ";
        }


    void recursionDFS(int src, unordered_map<int, bool> &visited_map)
    {
        cout<<src<<",";
        visited_map[src]=true;

        for (auto neighbour : adjList[src])
        {
            int node=neighbour.first;

            if (!visited_map[node])
                recursionDFS(node,visited_map);
        }

    }
    void dfsTraversal ()
    {
        unordered_map <int, bool> visited_map;
        cout<<endl;

        for (int src=0;src<vertices;src++) //

        {
            if (!visited_map[src])
            {
                recursionDFS(src, visited_map);
            }
        }
    }
};

int main()
{
    Graph G(7);
    G.displayEdgeList();
    G.addEdgeList(1,2);
    G.displayEdgeList();
    G.addEdges (0,4,DIR);
    G.addEdges (0,3,DIR);
    G.addEdges (0,2,DIR);
   // G.addEdges (3,5,DIR);
    //G.addEdges (2,5,DIR);
    G.addEdges (5,4,DIR);
    G.addEdges (1,6,DIR);
    G.addEdges (4,4,DIR);
    G.addEdges (6,2,DIR);
    G.displayAdjList();

    G.dfsTraversal();
    G.bfsTraversal();
    G.dijkastra(0);

}
