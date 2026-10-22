// Longest Increasing Path in Matrix

#include <bits/stdc++.h>
using namespace std;

int dfs(int row, int column, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if (dp[row][column]) return dp[row][column];
    dp[row][column] = 1;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i], nc = column + dc[i];
        if (nr >= 0 && nr < (int)matrix.size() && nc >= 0 && nc < (int)matrix[0].size() && matrix[nr][nc] > matrix[row][column]) {
            dp[row][column] = max(dp[row][column], 1 + dfs(nr, nc, matrix, dp));
        }
    }
    return dp[row][column];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m)), dp(n, vector<int>(m));
    for (auto &row : matrix) for (int &x : row) cin >> x;
    int answer = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) answer = max(answer, dfs(i, j, matrix, dp));
    cout << answer << '\n';
    return 0;
}
