// Merge Overlapping Intervals

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[l, r] : a) cin >> l >> r;
    sort(a.begin(), a.end());

    vector<pair<int, int>> ans;
    for (auto [l, r] : a) {
        if (ans.empty() || ans.back().second < l) {
            ans.push_back({l, r});
        } else {
            ans.back().second = max(ans.back().second, r);
        }
    }

    for (auto [l, r] : ans) cout << l << ' ' << r << '\n';
    return 0;
}
