//wap to print factorial of a number
#include<iostream>
using namespace std;
int factorial(int n){

    if(n<1){
        return 1;
    }

    int fact = n *factorial(n-1);
    return fact;

}
int main(){
    int n;
    cout<<"Enter the number till we have to calculate factorial  : ";
    cin>>n;
    cout<<"Factorial : "<<factorial(n)<<endl;
}
