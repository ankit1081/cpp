#include<iostream>
using namespace std;
void halfDiamondPattern(int n){
    for(int i = 1; i<=n;i++){
        cout<<"\n";
        for(int j=1;j<=i;j++ ){
            cout<<"*"<<" ";
        }
    }
    for(int i = n-1; i>=1;i--){
        cout<<"\n";
        for(int j=1;j<=i;j++ ){
            cout<<"*"<<" ";
        }
    }

}
int main() {
    int n ;
    cin>>n;
    halfDiamondPattern(n);
    return 0;
}