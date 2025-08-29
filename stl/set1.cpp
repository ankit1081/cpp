//wap to to search an element in set and return 1 if found else return -1
#include<iostream>
#include<set>

using namespace std;
int search(const set<int> Set,int n ){
    for(auto it : Set){
        if(it == n){
            return 1;
        }   
    }
    return -1;
}
int main() {
    set<int> Set = {3,2,14,5};
    cout<<search(Set,3)<<endl;
    return 0;
}