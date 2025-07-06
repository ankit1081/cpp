//wap to print n to 1 using recusrion
#include<iostream>
using namespace std;
void print(int n){
    if(n<1){
        return;
    }
    cout<<n<<endl;//stack winding ke time pe call hoga
    print(n-1);

}
int main(){
    int n;
    cout<<"Enter a no:";
    cin>>n;
    print(n);
}
