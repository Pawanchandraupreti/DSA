// Swim in Rising Water

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &row : grid) for (int &x : row) cin >> x;
    vector<vector<bool>> used(n, vector<bool>(n));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    heap.push({grid[0][0], 0, 0});
    int answer = 0, dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    while (!heap.empty()) {
        auto [level, row, column] = heap.top();
        heap.pop();
        if (used[row][column]) continue;
        used[row][column] = true;
        answer = max(answer, level);
        if (row == n - 1 && column == n - 1) break;
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = column + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !used[nr][nc]) heap.push({grid[nr][nc], nr, nc});
        }
    }
    cout << answer << '\n';
    return 0;
}
