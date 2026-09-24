// Flood Fill

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, sr, sc, color;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m));
    for (auto &row : image) for (int &x : row) cin >> x;
    cin >> sr >> sc >> color;

    int old = image[sr][sc];
    if (old != color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == old) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
    }

    for (auto &row : image) {
        for (int x : row) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
