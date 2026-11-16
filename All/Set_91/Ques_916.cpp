// Rotten Oranges

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> a[r][c];
            if (a[r][c] == 2) q.push({r, c});
            if (a[r][c] == 1) fresh++;
        }
    }
    int time = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (!q.empty()) {
        int sz = q.size();
        bool changed = false;
        while (sz--) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || a[nr][nc] != 1) continue;
                a[nr][nc] = 2;
                fresh--;
                changed = true;
                q.push({nr, nc});
            }
        }
        if (changed) time++;
    }
    cout << (fresh ? -1 : time) << '\n';
    return 0;
}
