//191. Number of 1 Bits
#include<iostream>
using namespace std;
class NoOf1Bits {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n!=0){
            if(n&1){
                count++;
            }
            n = n>>1;

        }
        return count;

    }
};
int main(){
    NoOf1Bits B;
    int n ;
    cout<<"enter the value :";
    cin>>n;
     int Ans = B.hammingWeight(n);
    cout<<"Ans is :"<<Ans;
    return 0;
}
