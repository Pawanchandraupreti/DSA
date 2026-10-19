// Unique Paths with Obstacles

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> dp(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cell;
            cin >> cell;
            if (cell == 1) dp[j] = 0;
            else if (i == 0 && j == 0) dp[j] = 1;
            else if (j > 0) dp[j] += dp[j - 1];
        }
    }
    cout << dp[m - 1] << '\n';
    return 0;
}
