#include<iostream>
using namespace std;
void print(int n){
    if(n<1){
        cout<<"\nReturning ......."<<n<<endl;
        return;
    }
    cout<<"Ankit..."<<n<<endl;//stack winding ke time pe call hoga
    print(n-1);

}
int main(){
    int n;
    print(10);
}
