#include<iostream>
#include<vector>
#include<utility>
using namespace std;
pair<vector<int>,vector<int>> seperate(vector<int>& vtr){
    vector<int> pos;
    vector<int> neg;
    for(auto num : vtr){
        if(num<0){
            neg.push_back(num);
        }
        else{
            pos.push_back(num);
        }
    }
    return {neg,pos};
}
int main() {
    vector<int> vtr = {-1,4,2,-5,8};
    pair<vector<int>,vector<int>> ans = seperate(vtr);
    cout<<"Negative : ";
    for(auto num : ans.first){
        cout<<num<<" ";
    }
    cout<<endl<<"Positive : ";
    for(auto num : ans.second){
        cout<<num<<" ";
    }
    return 0;
}
