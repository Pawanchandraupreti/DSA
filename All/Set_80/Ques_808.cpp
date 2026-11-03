// Minimum Changes for Valid Grid Path

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid) for (int &x : row) cin >> x;
    deque<pair<int, int>> q;
    vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
    q.push_front({0, 0});
    cost[0][0] = 0;
    int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};
    while (!q.empty()) {
        auto [row, column] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = column + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int extra = grid[row][column] == i + 1 ? 0 : 1;
                if (cost[nr][nc] > cost[row][column] + extra) {
                    cost[nr][nc] = cost[row][column] + extra;
                    if (extra) q.push_back({nr, nc});
                    else q.push_front({nr, nc});
                }
            }
        }
    }
    cout << cost[n - 1][m - 1] << '\n';
    return 0;
}
