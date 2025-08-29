//given an array of elemnts , find the kth largest from unique elements , means first remove duplicates then find kth largest
#include<iostream>
#include<set>
#include<vector>
using namespace std;
class KthLargestUnique{
public:

    int findKthLargestUnique(vector<int>& arr, int k){
        set<int, greater<int>> uniq(arr.begin(), arr.end());
        if(k>uniq.size()){
            return -1;
        }
        auto it = uniq.begin();
        advance(it,k-1);
        return *it;
    }
};

int main()
{
    KthLargestUnique k;
    vector<int> arr = {5,5,2,3,1,1,2,3,9,9};
    cout<<k.findKthLargestUnique(arr,3);
    return 0;
}
