// Minimum Path Sum Grid

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m));
    for (auto& row : dp) for (int& x : row) cin >> x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            int up = i ? dp[i - 1][j] : INT_MAX;
            int left = j ? dp[i][j - 1] : INT_MAX;
            dp[i][j] += min(up, left);
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}
