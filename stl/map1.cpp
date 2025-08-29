#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int,int> m1 = {{1,2},{2,3}};
    map<int,int> m2 = {{5,2},{5,2}};
    //printing the value
    for(auto num : m1 ){
        cout<<"Key="<<num.first<<" "<<"value= "<<num.second<<endl;
    }
    for(auto num : m2){
        cout<<"Key="<<num.first<<" "<<"value= "<<num.second<<endl;
    }

    m1[11] = 33;
    cout<<m1[11]<<endl;
    m1.erase(11);
    //finding the value in map 
    auto it = m1.find(11);
    if(it != m1.end()){
        cout<<it->first<<" "<<it->second<<endl;
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    else{
        cout<<"value not found"<<endl;
    }
    m1.insert({3,5});
    for(auto num : m1 ){
        cout<<"Key="<<num.first<<" "<<"value= "<<num.second<<endl;
    }
    cout<<".........."<<endl;
    m1.insert({3,6});
    for(auto num : m1 ){
        cout<<"Key="<<num.first<<" "<<"value= "<<num.second<<endl;
    }
    return 0;
}