//wap to print integer to character form of each number using recursion
#include<iostream>
using namespace std;
void print(int n, string ar[]){
    if (n==0){
        return;
    }
    int digit = n%10;
    n = n/10;
    print(n,ar);
    cout<<ar[digit];
    cout<<" ";
}
int main(){
    int n ;
    string ar[] = {"zero", "one" , "two" , "three" , "four" , "five ", "six", "seven" , "eight" ," nine "};
    cout<<"Enter the digits : ";
    cin>>n;
    print(n,ar);
}
