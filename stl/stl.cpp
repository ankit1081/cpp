#include<iostream>
#include<array>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
    //stl array implentation
    array<int,5> ar = {4,2,1,3,5};
    ar.front();
    
    //stl vector implentation
    vector<int> v ;
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);

    for(auto &num : v){
        num = num+10;
    }

    for ( int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }


    //stl stack implentation
    stack<int> st;
    st.push(10);
    cout<<st.top();
    st.pop();
    return 0;
}