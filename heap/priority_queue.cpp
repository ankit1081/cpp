#include<iostream>
#include<queue>

using namespace std;


int main()
{
    priority_queue<int>pq;
    pq.push(10);
    pq.push(12);
    pq.push(30);

    cout<<pq.top()<<endl;

    priority_queue<int, vector<int>,greater<int>> minHeap;

    minHeap.push(20);
    minHeap.push(10);
    minHeap.push(200);
    minHeap.push(50);

    cout<<minHeap.top()<<endl;

    priority_queue<int> temp(pq);
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }

}
