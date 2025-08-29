#include<iostream>
#include<climits>
using namespace std;
void printArray(int num[], int n ){
    cout<<"\nPrinting array :";
    for(int i =0 ; i< n; i++){
        cout<<num[i]<<" ";
    }

}
int getMAX(int num[], int n){
    /*predefined function
    maxi =max(maxi, num[i]);
    */
    int max =INT_MIN;
    for(int i =0 ; i<n ; i++){
        if (num[i]>max){
            max = num[i];
        }
    }
    return max;
}
int getMIN(int num[], int n){
    /*predefined function
    mini =min(mini, num[i]);
    */
    int min =INT_MAX;
    for(int i =0 ; i<n ; i++){
        if (num[i]<min){
            min = num[i];
        }
    }
    return min;
}
int sumOfArray(int num[],int n){
    int sum = 0;
    for(int i = 0 ; i<n; i++){
        sum = sum + num[i];
    }
    return sum;
}
bool search(int num[], int n , int key){
    for(int i=0; i<n; i++){
        if(key == num[i]){
            return true;
        }

    }
    return false;

}
void reverse(int num[], int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        swap(num[start],num[end]);
        start++;
        end--;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int num[100];
    cout<<"Enter the elements of the array : "<<endl;
    for (int i = 0; i<n ; i ++){
        cin>> num[i];
    }

    printArray(num,n);

    cout<<"\nMaximum value is "<<getMAX(num,n)<<endl;
    cout<<"\nMinimun value is "<<getMIN(num,n)<<endl;

    cout<<"\nSum of elements of the array is : "<<sumOfArray(num,n)<<endl;

    int key;
    cout <<"\n Enter the element to search for : ";
    cin>>key;
    bool found = search(num , n ,key);
    if ( found ){
        cout<<"key is present";
    }
    else{
        cout<<"key is not present ";
    }

    reverse(num , n);
    printArray(num,n);


    return 0;
}
