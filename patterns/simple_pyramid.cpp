#include<iostream>
using namespace std;

void simplePyramid(int n ){
    for( int i = 1 ; i<= n ; i++){
        cout<<"\n";
        for ( int j = 1 ; j<= i ; j++){
            cout<<"*"<<" ";
        }
    }
}
int main()
{
    int n ;
    cin>>n;
    simplePyramid(n);
    return 0;
}
