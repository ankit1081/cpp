#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
class Solution{
    public:
    string reverseString1(string& s){
        return string(s.rbegin(),s.rend());
    }
    
    
    string reverseString2(string& s){
        string s1 = s;
        reverse(s1.begin(),s1.end());
        return s1;
    }

    string reverseString3(string& s){
        string s1 = s;
        int n = s1.size();
        for(int i = 0; i< n/2; i++){
            swap(s1[i], s1[n-i-1]);
        }
        return s1;
    }
    
};
int main() {
    Solution S;
    string s = "Ankit";
    cout<<S.reverseString1(s)<<endl;
    cout<<S.reverseString2(s)<<endl;
    cout<<S.reverseString3(s)<<endl;
    return 0;
}