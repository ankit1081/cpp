// wap to find sum  of digits of a numeber.
#include <iostream>

using namespace std;

int sumOfDigits(int n){
    int sum = 0;
    while(n>0){
        n = n% 10;
        sum = sum + n;
        n = n/10;
    }
    return 0;
}
int main()
{
    int n;
    cout<< "Enter a number :\n";
    cin>>n;
    cout<<sumOfDigits(n);
    return 0;
}
