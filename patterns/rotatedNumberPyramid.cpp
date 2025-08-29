#include<iostream>
using namespace std;
void rotatedNumberPyramid(int n){
    int num = 0;
    for(int i = 1; i<=n;i++){
        cout<<"\n";
        for (int k = 1; k<=n-i;k++){
            cout<<" "<<" ";
        }
        for(int j = 1 ; j<= i ;j++){
            cout<<num+i<<" ";
        }
        num++;
    }
}
int main() {
    int n;
    cin>>n;
    rotatedNumberPyramid(n);
    return 0;
}