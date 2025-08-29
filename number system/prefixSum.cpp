#include<iostream>
#include<vector>
using namespace std;
class PrefixSum{
    vector<int> prefix;
    public:
        PrefixSum(const vector<int> &arr){
            int n = arr.size();
            prefix.resize(n);
            prefix[0]= arr[0];

            for(int i =1; i<n; i++){
                prefix[i]= prefix[i-1]+arr[i];
            }
        }

        int getRangedSum(int left ,int right){
            if (left== 0){
                return prefix[right];
            }
            return prefix[right]- prefix[left-1];
        }

        void printPrefix(){
            for(auto val : prefix){
                cout<<val<<" ";
            }
            cout<<endl;
        }
};
int main() {
    int n;
    cout<<"\nEnter no of elements :";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter "<< n <<" elements of the array : \n";
    for(int i = 0 ; i< n ; i ++){
        cin>> arr[i];
    }
    PrefixSum ps(arr);
    cout<<"\nPrefix Sum array : ";
    ps.printPrefix();

    int left, right;
    cout<<"Enter range to find :\n";
    cin>>left>>right;
    if(left<0 || right>=n || left>right){
        cout<<"Invalid range!\n";
    }
    else{
        int sum = ps.getRangedSum(left, right);
        cout<<"Ranged sum is :"<<sum;
    }


    return 0;
}
