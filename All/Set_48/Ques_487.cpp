// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), dp;
    for (int &x : a) cin >> x;

    for (int x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }

    cout << dp.size() << '\n';
    return 0;
}

