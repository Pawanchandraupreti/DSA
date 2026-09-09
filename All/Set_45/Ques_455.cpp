// Shortest Path in Binary Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto& row : a) for (int& x : row) cin >> x;

    if (a[0][0] || a[n - 1][n - 1]) {
        cout << -1;
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    a[0][0] = 1;
    int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (r == n - 1 && c == n - 1) {
            cout << a[r][c];
            return 0;
        }
        for (auto& dir : d) {
            int x = r + dir[0], y = c + dir[1];
            if (x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 0) {
                a[x][y] = a[r][c] + 1;
                q.push({x, y});
            }
        }
    }
    cout << -1;
    return 0;
}
