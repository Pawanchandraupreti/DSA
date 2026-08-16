// Count number of connected components in a grid (islands)

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
    int rows = grid.size();
    int cols = grid[0].size();
    visited[row][col] = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc] && grid[nr][nc] == 1) {
            dfs(nr, nc, grid, visited);
        }
    }
}

int countIslands(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    int islands = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                ++islands;
                dfs(i, j, grid, visited);
            }
        }
    }

    return islands;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << countIslands(grid);
    return 0;
}
