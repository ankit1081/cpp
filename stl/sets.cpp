#include<iostream>
#include<set>
using namespace std;
void display(const set<int> &s){
    for(auto val : s){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main() {
    set<int> s = {1,2,3};
    display(s);
    s.insert(4);
    display(s);
    s.emplace(5);
    display(s);
    return 0;
}