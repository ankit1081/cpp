#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
    public:
        int implementFind(string& text , string& part){
            int mlength = text.length(); 
            int plength = part.length();

            if(plength == 0 || plength>mlength){
                return -1;
            }
            //we are running ith loop till mlength-plength so that it stops at that length avoiding unsessary loop
            //eg - while searching for "ki" in "ankit" , i will run till length = 3
            for (int i = 0 ; i<= mlength-plength; i++){
                //taking a count loop to count the length of part
                int count = 0;
                while(count < plength && text[i+count] == part[count]){
                    count++;//check for next values 
                }
                if(count == plength){//if the length of count == length of part
                    return i;
                }
            }
            return -1;
        }
};
int main() {
    Solution S;
    string text = "ankit";
    string part = "it";
    cout<<S.implementFind(text,part);
    return 0;
}