// Sliding Window Median

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    multiset<int> box;
    auto median = [&]() {
        auto it = next(box.begin(), (k - 1) / 2);
        if (k % 2) return (double)*it;
        return (*it + *next(it)) / 2.0;
    };

    for (int i = 0; i < n; i++) {
        box.insert(a[i]);
        if (i >= k) box.erase(box.find(a[i - k]));
        if (i >= k - 1) cout << fixed << setprecision(1) << median() << ' ';
    }
    return 0;
}
