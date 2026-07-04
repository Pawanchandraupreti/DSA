// Longest increasing path in a matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }

    vector<vector<int>> memo(n, vector<int>(m, 0));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    function<int(int, int)> dfs = [&](int x, int y) {
        int &res = memo[x][y];
        if (res) return res;
        res = 1;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (a[nx][ny] > a[x][y]) res = max(res, 1 + dfs(nx, ny));
        }

        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) ans = max(ans, dfs(i, j));
    }

    cout << ans;
    return 0;
}