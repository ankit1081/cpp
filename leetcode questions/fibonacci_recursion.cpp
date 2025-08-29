//wap to print nth fibonacci number using recursion
#include<iostream>
using namespace std;
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cout<<"Enter the nth term of fibonnaci series u want to know : ";
    cin>>n;
    cout<<fib(n);
}
