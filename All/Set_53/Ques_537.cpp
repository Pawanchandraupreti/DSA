// Unique Paths

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> dp(m, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) dp[j] += dp[j - 1];
    }

    cout << dp[m - 1] << '\n';
    return 0;
}
