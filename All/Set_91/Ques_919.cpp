// Minimum Capacity to Ship Packages

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, days;
    cin >> n >> days;
    vector<int> a(n);
    int lo = 0, hi = 0;
    for (int &x : a) {
        cin >> x;
        lo = max(lo, x);
        hi += x;
    }
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int used = 1, load = 0;
        for (int x : a) {
            if (load + x > mid) {
                used++;
                load = 0;
            }
            load += x;
        }
        if (used <= days) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
    return 0;
}


