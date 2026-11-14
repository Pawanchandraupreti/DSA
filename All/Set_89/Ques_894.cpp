// Shortest Path in a Binary Grid

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (string &s : a) cin >> s;

    if (a[0][0] == '1' || a[n - 1][m - 1] == '1') {
        cout << "-1\n";
        return 0;
    }

    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    d[0][0] = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (a[nr][nc] == '1' || d[nr][nc] != -1) continue;
            d[nr][nc] = d[r][c] + 1;
            q.push({nr, nc});
        }
    }

    cout << d[n - 1][m - 1] << '\n';
    return 0;
}
