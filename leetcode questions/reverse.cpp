// leetcode problem 7 to reverse a signed integer and also return 0 in case of ans is out of range
# include<iostream>
#include<climits>
using namespace std;
class reverse {
public:
    int Reverse(int x) {

        int ans= 0;
        while(x!=0){
            int digit = x %10;
            if ((ans>INT_MAX/10)|| (ans<INT_MIN/10)){
                return 0 ;
            }
            ans = ans*10 + digit ;

            x = x /10;
        }
        return ans;

    }
};
int main(){
    reverse r;
    int x;
    cout<< "Enter an integer :";
    cin>>x;
    int Ans = r.Reverse(x);
    cout<<"Reversed no is:"<<Ans;
    return 0;
}
