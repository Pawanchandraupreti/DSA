// Flood Fill

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, row, column, color;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m));
    for (auto &line : image) for (int &x : line) cin >> x;
    cin >> row >> column >> color;
    int original = image[row][column];
    if (original == color) return 0;

    queue<pair<int, int>> q;
    q.push({row, column});
    image[row][column] = color;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == original) {
                image[nr][nc] = color;
                q.push({nr, nc});
            }
        }
    }
    for (auto &line : image) {
        for (int x : line) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
