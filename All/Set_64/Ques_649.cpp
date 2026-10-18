// Shortest Path in Binary Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid) for (int &x : row) cin >> x;

    queue<pair<int, int>> q;
    if (grid[0][0] == 0) {
        q.push({0, 0});
        grid[0][0] = 1;
    }
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0) {
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    cout << (grid[n - 1][m - 1] == 0 ? -1 : grid[n - 1][m - 1]) << '\n';
    return 0;
}

