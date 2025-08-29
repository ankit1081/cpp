//just count the numbers and return their frequency
#include<iostream>
#include<set>
#include<vector>
using namespace std;

class CountDuplicates{
public:
    int Count(vector<int>& arr){
        set<int>s;
        for(auto num : arr){
            s.insert(num);
        }
        return arr.size()-s.size();
    }
};
int main()
{
    CountDuplicates C;
    vector<int> arr1 = {1,2,3,1,2,3,1,2,3};
    cout<<C.Count(arr1)<<endl;//6
    vector<int> arr2 = {9,4,5,1,4,9,5,1};
    cout<<C.Count(arr2)<<endl;//4
    return 0;
}
