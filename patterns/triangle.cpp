#include<iostream>
using namespace std;

void traingle(int n){
    for ( int i = 1;i<=n;i++){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}

int main()
{
    int n ;
    cin>> n ;
    traingle(n);
    return 0;
}
