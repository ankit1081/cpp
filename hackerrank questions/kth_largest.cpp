#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class largest{
public:
    int kthlargest(vector<int>arr, int n){
        priority_queue<int,vector<int>> pq;
        for(auto num : arr){
            pq.push(num);
        }
        for(int i = 0; i<n-1 ; i++){
            pq.pop();
        }
        return pq.top();
    }
};
int main() {
    largest l;
    vector<int> arr = {3,7,9,1,0,4,2};
    int ans = l.kthlargest(arr,1);
    cout<<ans;
    return 0;
}