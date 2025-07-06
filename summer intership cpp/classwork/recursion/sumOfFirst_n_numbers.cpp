//wap to print sum of numbers from 1 to n
#include<iostream>
using namespace std;
int sum(int n){

    if(n<1){
        return 0;
    }

    int ans = n+sum(n-1);
    return ans;

}
int main(){
    int n;
    cout<<"Enter the number till we have to calculate : ";
    cin>>n;
    cout<<"Sum : "<<sum(n)<<endl;
}
