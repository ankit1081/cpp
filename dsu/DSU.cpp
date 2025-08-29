#include<iostream>
#include<vector>
using namespace std;
class Disjoint_Set{
    vector<int> leader;
public:
    Disjoint_Set(int number = 5){
        leader.resize(number);
        //vertex is my index and value at my index is leader

        for(int i =0 ; i<number ; i++){
            leader[i]= i;
        }

    }


    int find (int x){
        if(x==leader[x]){
            return x;
        }
        return find(leader[x]);

    }


    void Union(int x, int y){
        int xLeader= find(x);
        int yLeader = find(y);

        if(xLeader == yLeader){
            cout<<"\nAlready present";
            return;
        }
        else{
            leader[yLeader]=xLeader;
        }
    }

    void display(){
        cout<<"Displaying Leader : "<<endl;

    for(auto i:leader)
        cout<<i<<" ";
    cout<<endl;
    }

};
int main()
{
    Disjoint_Set DSU(4);
    DSU.display();
    DSU.Union(2,3);
    DSU.display();
    DSU.Union(2,3);
}
