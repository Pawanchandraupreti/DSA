// Integer Break Maximum Product

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int value = 2; value <= n; value++) {
        for (int part = 1; part < value; part++) dp[value] = max(dp[value], part * max(value - part, dp[value - part]));
    }
    cout << dp[n] << '\n';
    return 0;
}
