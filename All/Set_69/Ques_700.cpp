// Minimum Path Sum in Grid

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(m, INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int value;
            cin >> value;
            if (i == 0 && j == 0) dp[j] = value;
            else if (j == 0) dp[j] += value;
            else dp[j] = min(dp[j], dp[j - 1]) + value;
        }
    }
    cout << dp[m - 1] << '\n';
    return 0;
}
