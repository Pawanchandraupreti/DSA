// 0/1 Knapsack maximum value

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    if (!(cin >> n >> W)) return 0;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; ++i) cin >> weight[i];
    for (int i = 0; i < n; ++i) cin >> value[i];

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int cap = W; cap >= weight[i]; --cap) {
            dp[cap] = max(dp[cap], dp[cap - weight[i]] + value[i]);
        }
    }

    cout << dp[W];
    return 0;
}
