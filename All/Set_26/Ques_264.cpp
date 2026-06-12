// Sliding window median using two multisets

#include <bits/stdc++.h>
using namespace std;

struct MedianWindow {
    multiset<long long> lo, hi;

    void rebalance() {
        while (lo.size() > hi.size() + 1) {
            auto it = prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        }
        while (lo.size() < hi.size()) {
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    }

    void add(long long x) {
        if (lo.empty() || x <= *prev(lo.end())) lo.insert(x);
        else hi.insert(x);
        rebalance();
    }

    void remove(long long x) {
        auto it = lo.find(x);
        if (it != lo.end()) lo.erase(it);
        else {
            it = hi.find(x);
            if (it != hi.end()) hi.erase(it);
        }
        rebalance();
    }

    long long median() const { return *prev(lo.end()); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    MedianWindow mw;
    vector<long long> res;
    for (int i = 0; i < n; ++i) {
        mw.add(a[i]);
        if (i >= k) mw.remove(a[i - k]);
        if (i >= k - 1) res.push_back(mw.median());
    }

    for (size_t i = 0; i < res.size(); ++i) {
        if (i) cout << ' ';
        cout << res[i];
    }
    return 0;
}
