//231. Power of Two
#include<iostream>
#include<climits>
using namespace std;
class PowerOfTwo{
public:
    bool IsPowerOfTwo(int n){
        int ans = 1 ;
        for (int i=0 ; i<= 30 ; i++){
            if (ans == n ){
                return true;
            }
            if (ans< INT_MAX/2)
            ans = ans *2;
        }
        return false;
    }
};
int main(){
    PowerOfTwo p;
    int n ;
    cout<< "Enter the number to check :";
    cin>>n;
    int value = p.IsPowerOfTwo(n);
    cout<<value;
    return 0;
}
