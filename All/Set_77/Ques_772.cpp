// Shortest Path with Obstacle Elimination

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, limit;
    cin >> n >> m >> limit;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid) for (int &x : row) cin >> x;
    vector<vector<int>> best(n, vector<int>(m, INT_MAX));
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    best[0][0] = 0;
    int steps = 0, dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [row, column, removed] = q.front();
            q.pop();
            if (row == n - 1 && column == m - 1) {
                cout << steps << '\n';
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = column + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int next = removed + grid[nr][nc];
                    if (next <= limit && next < best[nr][nc]) {
                        best[nr][nc] = next;
                        q.push({nr, nc, next});
                    }
                }
            }
        }
        steps++;
    }
    cout << -1 << '\n';
    return 0;
}

