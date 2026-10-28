// Median of Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), merged;
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(merged));
    if (merged.size() % 2) cout << fixed << setprecision(5) << (double)merged[merged.size() / 2] << '\n';
    else cout << fixed << setprecision(5) << (merged[merged.size() / 2 - 1] + merged[merged.size() / 2]) / 2.0 << '\n';
    return 0;
}



