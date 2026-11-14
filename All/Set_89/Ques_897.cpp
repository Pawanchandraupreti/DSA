// Range Sum Queries with a Fenwick Tree

#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, long long v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }

    long long sum(int i) {
        long long ans = 0;
        for (; i > 0; i -= i & -i) ans += bit[i];
        return ans;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Fenwick ft(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ft.add(i, x);
    }

    while (q--) {
        int t, i, v;
        cin >> t >> i >> v;
        if (t == 1) {
            ft.add(i, v);
        } else {
            cout << ft.sum(v) - ft.sum(i - 1) << '\n';
        }
    }
    return 0;
}
