// Pacific Atlantic Water Flow Count

#include <bits/stdc++.h>
using namespace std;

void flow(queue<pair<int, int>> &q, vector<vector<int>> &height, vector<vector<bool>> &visited) {
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [row, column] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = column + dc[i];
            if (nr >= 0 && nr < (int)height.size() && nc >= 0 && nc < (int)height[0].size() && !visited[nr][nc] && height[nr][nc] >= height[row][column]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> height(n, vector<int>(m));
    for (auto &row : height) for (int &x : row) cin >> x;
    vector<vector<bool>> pacific(n, vector<bool>(m)), atlantic(n, vector<bool>(m));
    queue<pair<int, int>> first, second;
    for (int i = 0; i < n; i++) {
        first.push({i, 0}); pacific[i][0] = true;
        second.push({i, m - 1}); atlantic[i][m - 1] = true;
    }
    for (int j = 0; j < m; j++) {
        first.push({0, j}); pacific[0][j] = true;
        second.push({n - 1, j}); atlantic[n - 1][j] = true;
    }
    flow(first, height, pacific);
    flow(second, height, atlantic);
    int answer = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) answer += pacific[i][j] && atlantic[i][j];
    cout << answer << '\n';
    return 0;
}
