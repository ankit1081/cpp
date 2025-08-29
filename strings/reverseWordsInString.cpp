//leetcode question 186 - Reverse words in string
//eg - "the sky is blue" , op - "blue is the sky "
//approch - reverse the whole vector and then reverse each words of the reversed vector
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution{
public:
    //helper function for reversing words in string
    void reverse(vector<char>& s, int start, int end){
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    //main function to reverse the words 
    void reverseWords(vector<char>& s){
        int n = s.size();
        //firstly reverse the whole string 
        reverse(s,0,n-1);

        //reverse word of reversed vector
        int start = 0;
        for (int end = 0; end <= n ; end++){
            //
            if(s[end] == ' ' || end == n){
                //reverse word from start till wide space or null size reached
                reverse(s,start,end-1);
                //the new start will point from end+1 of reversed word
                start = end+1;
            }
        }
    }
};
int main(){
    Solution S;
    vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    S.reverseWords(s);
    for(char c : s){
        cout<<c;
    }

}