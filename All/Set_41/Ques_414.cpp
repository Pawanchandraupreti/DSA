// Fenwick Tree Range Sum

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int size;

public:
    explicit FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void update(int index, long long value) {
        while (index <= size) {
            tree[index] += value;
            index += index & (-index);
        }
    }

    long long query(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }

    long long rangeQuery(int left, int right) {
        if (left > right) return 0;
        return query(right) - (left > 1 ? query(left - 1) : 0);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1);
    FenwickTree ft(n);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        ft.update(i, arr[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int index;
            long long value;
            cin >> index >> value;
            ft.update(index, value - arr[index]);
            arr[index] = value;
        } else {
            int left, right;
            cin >> left >> right;
            cout << ft.rangeQuery(left, right) << '\n';
        }
    }
    return 0;
}

