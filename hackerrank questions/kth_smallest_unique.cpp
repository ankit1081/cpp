//given an array of elemnts , find the kth largest from unique elements , means first remove duplicates then find kth largest
#include<iostream>
#include<set>
#include<vector>
using namespace std;
class KthSmallestUnique{
public:

    int findKthSmallestUnique(vector<int>& arr, int k){
        set<int> uniq(arr.begin(), arr.end());
        if(k>uniq.size()){
            return -1;
        }
        auto it = uniq.begin();
        advance(it,k-1);
        return *it;

        /*
        auto it = uniq.begin();
        int count = 1;
        for (; it != uniq.end() && count < k; ++it, ++count);

        return (it != uniq.end()) ? *it : -1;
        */

    }
};

int main()
{
    KthSmallestUnique k;
    vector<int> arr = {5,5,2,3,1,1,2,3,9,9};
    cout<<k.findKthSmallestUnique(arr,4);
    return 0;
}
