#include<iostream>
using namespace std;

class Heap{
    int *arr;//a pointer that will store my array
    int capacity;
    int index;
public:
    Heap(int n = 5){
        capacity =n;
        arr = new int[capacity]( );
        index = 0;
    }

    int parent(int i){
        //parent = (i-1)/2
        return (i-1)/2;
    }

    int left_child(int i){
        return 2*i+1;
    }

    int right_child(int i){
        return 2*i+2;
    }

    void insertHeap(int num){
        if(index == capacity){
            cout<<endl<<"Stack Overflow";
            return;
        }
        arr[index] = num ;

        cout<<"\nNum="<< num <<" inserted at index="<<index;

        cout<<"\nRepositioning";

        int currentIndex = index;

        while(currentIndex>0){
            int parentIndex = parent(currentIndex);
            if(arr[currentIndex]<arr[parentIndex]){
                swap(arr[parentIndex],arr[currentIndex]);
                currentIndex = parentIndex;
            }
            else{
                break;
            }
        }
        cout<<"\nElement inserted and repositioned.";
        cout<<endl;
        index++;
    }

    void printHeap(){
        cout<<"\nPrinting Heap :\n ";
        for(int i =0 ; i<index;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int top (){
        //write code to maintian empty heap too
        if (index == 0) {
            cout << "Heap is empty.\n";
            return -1;
        }
        return arr[0];
    }
    void heapify(int i ){
        int smallest = i;
        int left = left_child(i);
        int right = right_child(i);

        if (left<index && arr[left]<arr[smallest]){
            smallest = left;
        }
        if (right<index && arr[right]<arr[smallest]){
            smallest = right;
        }
        if( smallest != i){
            swap(arr[i],arr[smallest]);
            heapify(smallest);
        }

    }

    void deleteHeap(){
        if (index == 0) {
            cout << "Heap is empty, nothing to delete.\n";
            return;
        }

        cout << "\nDeleting root element: " << arr[0];
        //swapping first an last
        swap(arr[0], arr[index]);
        index --;
        heapify(0);
    }

//create a destructor code too
    ~Heap(){
        delete[] arr;
    }


};
int main()
{
    Heap heap(3);
    heap.printHeap();
    heap.insertHeap(10);
    heap.insertHeap(20);
    heap.insertHeap(5);
    heap.printHeap();


}
