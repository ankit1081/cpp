//segment tree is better in terms of range query when compared to fenwick tree
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
    int n;
    vi maxTree;
    vi minTree;
    vi avgTree;



    void buildTree(const vi &st) {
        n = st.size();
        maxTree.resize(2 * n);
        minTree.resize(2 * n);
        avgTree.resize(2 * n);

        // Fill leaf nodes
        for (int i = 0; i < n; i++) {
            maxTree[n + i] = st[i];
            minTree[n + i] = st[i];
            avgTree[n + i] = st[i];
        }

        // Build internal nodes
        for (int i = n - 1; i > 0; i--) {
            maxTree[i] = max(maxTree[2 * i], maxTree[2 * i + 1]);
            minTree[i] = min(minTree[2*i],minTree[2*i+1]);
            sumTree[i] = sumTree[2*i]+sumTree[2*i+1];
        }
    }

public:
    SegmentTree(const vi &arr) {
        buildTree(arr);
    }

    // Query maximum in range [l, r)
    int rangeMax(int l, int r) {
        l += n;
        r += n;
        int maxVal = INT_MIN;
        while (l < r) {
            if (l % 2 == 1) maxVal = max(maxVal, maxTree[l++]);
            //if (l % 2 == 1){for odd
            // maxVal = max(maxVal, maxTree[l]);
            //i++
            //}
            if (r % 2 == 0) maxVal = max(maxVal, maxTree[--r]);
            //if (r % 2 == ){for even
               // maxVal = max(maxVal, maxTree[r]);
               // r--;
               // }
            l /= 2;
            r /= 2;
        }

        return maxVal;
    }

    // Update index pos to value val
    void update(int pos, int val) {
        pos += n;
        maxTree[pos] = val;

        for (pos /= 2; pos > 0; pos /= 2) {
            maxTree[pos] = max(maxTree[2 * pos], maxTree[2 * pos + 1]);
        }
    }
};

int main() {
    vi st = {2, 5, 1, 4, 9, 3};
    SegmentTree seg(st);

    cout << "Max in range [1, 5): " << seg.rangeMax(1, 5) << endl;  // Output: 9

    seg.update(2, 10);  // Update st[2] = 10

    cout << "After update, Max in range [1, 5): " << seg.rangeMax(1, 5) << endl;  // Output: 10

    return 0;
}

