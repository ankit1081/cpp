#include<iostream>
using namespace std;
void numberPyramid(int n){
    int a = 1;
    for(int i = 1 ; i<= n; i++){
        cout<<"\n";
        
        for(int j = 1 ; j<=i;j++){
            cout<<a<<" ";
        }
        a++;
    }
}
int main() {
    int n ;
    cin>>n;
    numberPyramid(n);
    return 0;
}