// Flood Fill

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, sr, sc, color;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row : a) for (int &x : row) cin >> x;
    cin >> sr >> sc >> color;

    int old = a[sr][sc];
    if (old != color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        a[sr][sc] = color;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == old) {
                    a[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
    }
    for (auto &row : a) {
        for (int x : row) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}


