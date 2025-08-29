#include<iostream>
using namespace std;
void hourglass(int n){
    for ( int i = n;i >=1;i--){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
    for ( int i = 2;i<=n;i++){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
int main() {
    int n ;
    cin>>n;
    hourglass(n);
    return 0;
}