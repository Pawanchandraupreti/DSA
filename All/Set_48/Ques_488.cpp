// Number of Islands

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string &row : grid) cin >> row;

    int ans = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '1') continue;
            ans++;
            queue<pair<int, int>> q;
            q.push({i, j});
            grid[i][j] = '0';
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1') {
                        grid[nr][nc] = '0';
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

