
/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;
//we will use a maxheap for left side of array from mid and minheap for right side of the array from mid
    //case -1 : if array has off no of elements then we (maxheap = minheap+1) or maxheap has one more element than minheap in such case , so we will return top elemnt of maxheap as median
    //case -2 : if the array has even no of elements then (minheap = maxheap), so we take top element of meaxheap and minheap and do (top1+top2)/2 to get the median
    // case - 3 : while adding an element in the array ,compare from the top element of left maxheap and add that accordingly into left or right side of the array, if the maxheap = minheap +2 , or we can say maxheap has size more than 1 from minheap , then we pop the top element of maxheap and push it into the minheap ,making case 2 . and vice versa making case 1.


vector<double> runningMedian(vector<int> a) {
    vector<double> median;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int num : a) {
            //pushing the elements
        if (maxheap.empty() || num <= maxheap.top())
            maxheap.push(num);
        else
            minheap.push(num);

         //balancing
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
         //finding median
        if (maxheap.size() == minheap.size())
            median.push_back((maxheap.top() + minheap.top()) / 2);
        else
            median.push_back(maxheap.top() * 1);
    }
    return median;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<double> result = runningMedian(a);

    for (double val : result)
        cout << fixed << setprecision(1) << val << "\n";

    return 0;
}

