#include<iostream>
#include<vector>
using namespace std;

class FenwickTree{
    vector<int> tree;
    int size;
    int lsb(int i){
        return i &(-i);
    }
public:
    FenwickTree(int n){
        size = n;
        tree.resize(size+1, 0);// size+1 because we work with index 1 instead of index 0 in BIT and putting 0 to initilized all values as 0 in start
    }

    void update(int i, int delta){
        while(i<=size){
            tree[i]+=delta;
            i+=lsb(i);//creating new value of i , because it works on certain range
        }
    }

    int query(int i ){
        int sum = 0;
        while(i>0){
            sum+=tree[i];
            i-=lsb(i);
        }
        return sum;
    }

    int rangedSum(int l, int r){

        return query(r)-query(l-1);
    }

    void printTree(){
        for(int i =1; i<size; i++){
            cout<<"BIT :\n";
            cout<<tree[i]<<" ";
        }
        cout<<endl;

    }
};
int main()
{
    int n , data;
    cout<<"Enter the size of the array :";
    cin>>n;

    vector<int>arr;

    cout<<"\nEnter the values in the array :";
    for(int i =0 ; i< n ; i++){
        cin>> data;
        arr.push_back(data);
    }

    cout<<"\ndisplaying array : ";
    for ( auto  value : arr){
        cout<<value<< " ";
    }
    cout<<endl;

    FenwickTree ft(n);

    for( int i =0; i<n ;i++){
        ft.update(i+1, arr[i]);
    }
    ft.printTree();

    cout << "Sum of first 5 elements: " << ft.query(5) << endl;
    cout << "Sum from 3 to 6: " << ft.rangedSum(3, 6) << endl;

    // Update example
    ft.update(4, 2); // Add 2 to arr[3] (since it's 1-based)
    cout << "Updated sum from 3 to 6: " << ft.rangedSum(3, 6) << endl;


	ft.printTree();

    return 0;
}
