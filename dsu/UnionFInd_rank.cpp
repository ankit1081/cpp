#include<iostream>
#include<vector>
using namespace std;

class UnionFind{
    vector<int>parent;
    vector<int> rank;

public:
    UnionFind(int size = 5){//default value of size is 5 here
        parent.resize(size);
        rank.resize(size,0);
        //initializing all th elements as self parent
        for(int i =0 ; i<size; i++){
            parent [i]=i;
        }
    }

    int find (int i){
        if (parent[i]!= i) {
            parent[i] = find(parent[i]) ;// path compresssion technique
        }
        return i;
        
    }

    void unite(int i , int j ){
        int irep = find(i);
        int jrep = find(j);

        if(irep ==jrep){
            cout<<"ALREADY PRESENT IN SAME SET\n";
        }
        else{
            //union by rank 
            if(rank[irep]>rank[jrep]){
                parent[jrep]=irep;
            }
            else if(rank[jrep]>rank[irep]){
                parent[irep]= jrep;
            }
            else{//rank[irep] == rank [jrep]
                parent[jrep] = irep ;
                rank[irep]++;
            }
                 
        }
        
    }
    void printParents() {
        cout << "\nParent Array:\n";
        for (int i = 0; i < parent.size(); i++) {
            cout << "Element " << i << " -> Parent: " << parent[i] << endl;
        }
    }    

};

int main() {
int size = 7;
    UnionFind uf(size);

    // Perform some union operations
    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.unite(5, 6);
    uf.unite(2, 4); // Merge two sets

    // Query representatives
    cout << "\nFind representatives:\n";
    for (int i = 0; i < size; i++) {
        cout << "Representative of " << i << " is: " << uf.find(i) << endl;
    }

    // Print internal parent array
    uf.printParents();
    
}