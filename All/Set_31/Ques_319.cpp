// Merge two sorted arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    vector<long long> res; res.reserve(n + m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i < n) res.push_back(a[i++]);
    while (j < m) res.push_back(b[j++]);
    for (size_t t = 0; t < res.size(); ++t) {
        if (t) cout << ' ';
        cout << res[t];
    }
    return 0;
}


