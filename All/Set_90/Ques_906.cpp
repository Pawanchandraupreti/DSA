// Maximum Number of Non-overlapping Meetings

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[s, e] : a) cin >> s >> e;
    sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second < y.second;
    });

    int ans = 0, end = INT_MIN;
    for (auto [s, e] : a) {
        if (s >= end) {
            ans++;
            end = e;
        }
    }
    cout << ans << '\n';
    return 0;
}

