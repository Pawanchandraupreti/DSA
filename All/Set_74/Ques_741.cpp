// Minimum Effort Path

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> heights(n, vector<int>(m));
    for (auto &row : heights) for (int &x : row) cin >> x;
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    distance[0][0] = 0;
    heap.push({0, 0, 0});
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    while (!heap.empty()) {
        auto [effort, row, column] = heap.top();
        heap.pop();
        if (row == n - 1 && column == m - 1) break;
        if (effort != distance[row][column]) continue;
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = column + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int next = max(effort, abs(heights[row][column] - heights[nr][nc]));
                if (next < distance[nr][nc]) {
                    distance[nr][nc] = next;
                    heap.push({next, nr, nc});
                }
            }
        }
    }
    cout << distance[n - 1][m - 1] << '\n';
    return 0;
}
