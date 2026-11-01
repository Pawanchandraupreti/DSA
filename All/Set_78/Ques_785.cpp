// Largest Plus Sign Order

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mines;
    cin >> n >> mines;
    vector<vector<int>> grid(n, vector<int>(n, 1));
    while (mines--) {
        int row, column;
        cin >> row >> column;
        grid[row][column] = 0;
    }
    vector<vector<int>> dp(n, vector<int>(n, n));
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) count = grid[i][j] ? count + 1 : 0, dp[i][j] = min(dp[i][j], count);
        count = 0;
        for (int j = n - 1; j >= 0; j--) count = grid[i][j] ? count + 1 : 0, dp[i][j] = min(dp[i][j], count);
    }
    int answer = 0;
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) count = grid[i][j] ? count + 1 : 0, dp[i][j] = min(dp[i][j], count);
        count = 0;
        for (int i = n - 1; i >= 0; i--) count = grid[i][j] ? count + 1 : 0, dp[i][j] = min(dp[i][j], count), answer = max(answer, dp[i][j]);
    }
    cout << answer << '\n';
    return 0;
}
