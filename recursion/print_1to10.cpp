#include<iostream>
using namespace std;
void print(int n,int end){
    if(n>end){
        cout<<"\nReturning ......."<<n<<endl;
        return;
    }
    cout<<"Ankit..."<<n<<endl;
    print(n+1,end);

}
int main(){
    int n;
    int end;
    print(1,10);
}
