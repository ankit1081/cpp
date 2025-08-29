//from an array of elements , count the frequncy of elements and return the kth largest frequent element

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>


using namespace std;
typedef pair<int,int> pi;

class KthSmallestFrequent{
public:
    int findKthSmallestFrequent(vector<int>& arr, int k){
        unordered_map<int,int> freq;
        for(auto num : arr){
            freq[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto& it : freq){
            pq.push({it.second,it.first});
        }
        for(int i =0 ; i<k-1 && !pq.empty() ; i++){
            pq.pop();
        }
        return pq.empty()? -1 : pq.top().second;


    }
};

int main()
{
    KthSmallestFrequent k;
    vector<int> arr = {1,2,5,3,1,1,2,5,6};
    cout<<k.findKthSmallestFrequent(arr,2)<<endl;//6
    cout<<k.findKthSmallestFrequent(arr,1)<<endl;//3
    return 0;

}
