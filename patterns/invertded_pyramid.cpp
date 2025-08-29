#include<iostream>
using namespace std;
 void invertedPyramid(int n){
    for(int i = n ; i>=1; i--){
        cout<<"\n";
        for(int j = 1 ; j <=i ; j++){
            cout<<"* ";
        }
    }
 }
int main()
{
    int n ;
    cin>>n;
    invertedPyramid(n);
    return 0;

}
