// Minimum Path Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dp[i][j];
            if (i == 0 && j == 0) continue;
            int up = (i > 0 ? dp[i - 1][j] : INT_MAX);
            int left = (j > 0 ? dp[i][j - 1] : INT_MAX);
            dp[i][j] += min(up, left);
        }
    }

    cout << dp[n - 1][m - 1] << '\n';
    return 0;
}
