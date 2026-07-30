// Shortest path in a weighted grid with path reconstruction

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    vector<vector<ll>> dist(n, vector<ll>(m, INF));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<char>> moveDir(n, vector<char>(m, '?'));
    priority_queue<pair<ll, pair<int,int>>, vector<pair<ll, pair<int,int>>>, greater<pair<ll, pair<int,int>>>> pq;
    dist[0][0] = a[0][0];
    pq.push({dist[0][0], {0, 0}});

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    const char mv[4] = {'U', 'D', 'L', 'R'};

    while (!pq.empty()) {
        auto [d, cell] = pq.top(); pq.pop();
        int x = cell.first, y = cell.second;
        if (d != dist[x][y]) continue;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] > d + a[nx][ny]) {
                dist[nx][ny] = d + a[nx][ny];
                parent[nx][ny] = {x, y};
                moveDir[nx][ny] = mv[k];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    if (dist[n - 1][m - 1] == INF) {
        cout << -1;
        return 0;
    }

    string path;
    for (int x = n - 1, y = m - 1; !(x == 0 && y == 0); ) {
        char c = moveDir[x][y];
        path.push_back(c);
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    reverse(path.begin(), path.end());
    cout << dist[n - 1][m - 1] << '\n' << path.size() << '\n' << path;
    return 0;
}


