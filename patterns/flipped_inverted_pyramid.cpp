#include<iostream>
using namespace std;
void flippedInvertedPyramid(int n){
    for ( int i = n;i>=1;i--){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" "<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
int main() {
    int n ;
    cin>>n;
    flippedInvertedPyramid(n);
    return 0;
}