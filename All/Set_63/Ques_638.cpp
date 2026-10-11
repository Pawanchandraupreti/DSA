// Number of Islands

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string &row : grid) cin >> row;

    int islands = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] != '1') continue;
            islands++;
            queue<pair<int, int>> q;
            q.push({r, c});
            grid[r][c] = '0';
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dr[i], ny = y + dc[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1') {
                        grid[nx][ny] = '0';
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << islands << '\n';
    return 0;
}
