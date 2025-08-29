//wap to swap alternates elements in an array
#include<iostream>
using namespace std;
void swapAlternates(int arr[], int size){
    for(int i = 0; i<size-1;i += 2){
        swap(arr[i],arr[i+1]);
    }
    cout<<"\nSwapped  Array :";
    for(int i =0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int arr[ ]={2,4,1,8,5,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Array :";
    for(int i =0 ; i<size; i++){
        cout<<arr[i]<<" ";
    }
   swapAlternates(arr,size);
    return 0;
}