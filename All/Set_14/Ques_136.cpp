// Fenwick Tree (Binary Indexed Tree) - Prefix Sum Query

#include <iostream>
#include <vector>
using namespace std;

class Fenwick {
    vector<long long> bit;
    int n;

public:
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int delta) {
        for(idx++; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }

    long long prefixSum(int idx) {
        long long sum = 0;
        for(idx++; idx > 0; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }

    long long rangeSum(int l, int r) {
        if(l > r) return 0;
        return prefixSum(r) - (l ? prefixSum(l - 1) : 0);
    }
};

int main() {
    vector<int> arr = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2};
    int n = arr.size();

    Fenwick ft(n);
    for(int i = 0; i < n; i++) ft.update(i, arr[i]);

    cout << ft.rangeSum(0, 4) << "\n";
    ft.update(3, 2);
    cout << ft.rangeSum(0, 4);
}
