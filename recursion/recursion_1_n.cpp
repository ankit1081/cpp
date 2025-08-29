//wap to print 1 to n using recusrion
#include<iostream>
using namespace std;
void print(int n){
    if(n<1){
        return;
    }
    print(n-1);
    cout<<n<<endl;//stack unwinding ke time pe call hoga
}
int main(){
    int n;
    cout<<"Enter a no:";
    cin>>n;
    print(n);
}
