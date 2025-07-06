#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertex){
        vertices = vertex;
        adjMatrix.resize(vertices, vector<int>(vertices,0));

    }
    void addEdges(int row , int column,bool directed = true){
        if(row>=vertices || column>=vertices || row<0 || column<0){
            cout<<"\n Out of bound error";
            return;
        }
        adjMatrix[row][column]=1;

        if(directed){
            adjMatrix[column][row]=1;
        }
    }
    void display(){
        cout<<"\n Adjacency matrix - vector of vector - 2D vector";
        cout<<"\n  ";
        for(int i = 0 ; i< vertices ; i++){
            cout<<i<<" ";

        }
        for(int i =0 ; i<vertices; i++){
            cout<<endl;
            cout<<i<<" ";
            for (int j =0 ; j<vertices; j++){
                cout<< adjMatrix[i][j]<<" ";
            }

        }
    }
};
void addVertex(){

}
int main(){
    Graph G(6);

    G.addEdges(0,1);

    G.addEdges(1,3);
    G.addEdges(1,4);
    G.addEdges(2,3);



    G.addEdges(4,5,0);


    G.display();
}
