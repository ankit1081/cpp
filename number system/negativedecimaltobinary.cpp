#include<iostream>
using namespace std;

int main(){
    int n ;
    cout<<"Enter a number :"<<endl;
    cin>>n;

    unsigned int mask = 1 << 4;
    string binary = "";

    for (int i=0; i<4;i++){
        if (n & mask){
            binary+='1';
        }
        else{
            binary+='0';
        }
        mask = mask >> 1;
    }
    cout<< "32 bit binary list is :"<<binary<<endl;
}
