// Binary Indexed Tree (Fenwick Tree) - Prefix Sum Query

#include <iostream>
#include <vector>
using namespace std;

void update(vector<int>& bit, int idx, int val, int n) {
    while(idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(vector<int>& bit, int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    vector<int> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7};
    int n = arr.size();

    vector<int> bit(n + 1, 0);
    for(int i = 0; i < n; i++) {
        update(bit, i + 1, arr[i], n);
    }

    cout << query(bit, 5) << "\n";

    update(bit, 3, 4, n);
    cout << query(bit, 5);
}

