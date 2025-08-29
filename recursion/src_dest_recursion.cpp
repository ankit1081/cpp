//wap to reach from source to destination using recursion
#include<iostream>
using namespace std;
void reached(int src, int dest){
    cout<<"Source : "<<src<< " Destination : " <<dest<<endl;
    if(src== dest){
        cout<<"Reached"<<endl;
        return;
    }
    reached(src+1, dest);
}
int main(){
    int src, dest;
    cout<<"Enter the source point : ";
    cin>>src;
    cout<<"Enter the destination point : ";
    cin>>dest;
    reached(src,dest);
}
