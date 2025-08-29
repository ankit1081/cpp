#include<iostream>
using namespace std;
class Heap{
    int arr[100];
    int size ;

    
    public:
        //constructor
        Heap(){
            size = 0 ;
            arr[0] = -1;
        }
        void insert(int value){
            //we are incresing the size by 1 beacause we want to leave the 0th index empty 
            size = size+1;
            int index = size;
            arr[index] =value;

            //making condtion to check if inserted element is greater that parent in maxheap
            while(index > 1){
                int parent = index /2;
                if (arr[parent]<arr[index]){
                    swap (arr[parent], arr[index]);
                    //now old parent index will be new index , so we check up too
                    index = parent;
                }
                else{
                    return;
                }  
            }
        }
        void print(){
            for (int i = 1 ; i<=size; i++){
                cout << arr[i]<<" ";
            }
            cout<<endl;
        }   
};

int main() {
    Heap heap;
    heap.insert(40);
    heap.insert(30);
    heap.insert(20);
    heap.print();
    heap.insert(50);
    heap.print();
    
    return 0;
}