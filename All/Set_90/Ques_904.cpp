// Number of Islands

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (string &s : a) cin >> s;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int ans = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (a[r][c] != '1') continue;
            ans++;
            queue<pair<int, int>> q;
            q.push({r, c});
            a[r][c] = '0';
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dr[k], ny = y + dc[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '1') {
                        a[nx][ny] = '0';
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
