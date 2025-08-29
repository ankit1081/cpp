#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> pi;
class GetDuplicates{
public:
    vector<pi> Duplicates(vector<int>& arr){
        map<int,int> m;
        for(auto& num : arr){
            m[num]++;
        }
        vector<pi> dup;
        for(auto& num : m){
            if(num.second > 1){
                dup.push_back({num.first, num.second-1});//doing -1 so that we do not count the original occurance
            }
        }
        return dup;
    }
};
int main()
{
    GetDuplicates D;
    vector<int> arr = {1,2,3,1,2,3,1,2,1};
    vector<pi> ans = D.Duplicates(arr);
    for(auto &num : ans){
        cout<<num.first<<"->"<<num.second<<endl;
    }
    return 0;
}
