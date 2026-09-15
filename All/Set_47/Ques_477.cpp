// Merge Intervals

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    vector<pair<int, int>> merged;
    for (auto [l, r] : v) {
        if (merged.empty() || l > merged.back().second) merged.push_back({l, r});
        else merged.back().second = max(merged.back().second, r);
    }

    for (auto [l, r] : merged) cout << l << ' ' << r << '\n';
    return 0;
}


