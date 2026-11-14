// 0/1 Knapsack

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cap;
    cin >> n >> cap;
    vector<int> dp(cap + 1);
    for (int i = 0; i < n; i++) {
        int w, val;
        cin >> w >> val;
        for (int c = cap; c >= w; c--)
            dp[c] = max(dp[c], dp[c - w] + val);
    }
    cout << dp[cap] << '\n';
    return 0;
}
