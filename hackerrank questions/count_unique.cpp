#include<iostream>
#include<set>
#include<vector>
using namespace std;
class CountUnique{
public:
    int Count(vector<int>& arr){
        set<int> unq ;
        for(auto num : arr){
            unq.insert(num);
        }
        return unq.size();
    }
};
int main()
{
    CountUnique C;
    vector<int> arr = {1,1,5,2,4,4};
    cout<<C.Count(arr);
    return 0;
}
