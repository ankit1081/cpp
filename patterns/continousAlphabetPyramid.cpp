#include<iostream>
using namespace std;
void continousAlphabetPyramid(int n){
    int num = 65;
    for(int i = 1;i<=n;i++){
        cout<<"\n";

        for(int j = 1 ; j<=i;j++){
            char ch = int(num);
            cout<<ch<<" ";
            num++;
            
        }
        
    }
}
int main() {
    int n ;
    cin>>n;
    continousAlphabetPyramid(n);
    return 0;
}