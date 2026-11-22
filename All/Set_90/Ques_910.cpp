// Minimum Coins for a Target Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coin(n);
    for (int &x : coin) cin >> x;
    vector<int> dp(sum + 1, sum + 1);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
        for (int x : coin) {
            if (x > i) continue;
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    cout << (dp[sum] > sum ? -1 : dp[sum]) << '\n';
    return 0;
}


