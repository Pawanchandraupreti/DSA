// Number of Distinct Islands

#include <bits/stdc++.h>
using namespace std;

void visit(int row, int column, int baseRow, int baseColumn, vector<vector<int>> &grid, vector<pair<int, int>> &shape) {
    if (row < 0 || row >= (int)grid.size() || column < 0 || column >= (int)grid[0].size() || grid[row][column] == 0) return;
    grid[row][column] = 0;
    shape.push_back({row - baseRow, column - baseColumn});
    visit(row + 1, column, baseRow, baseColumn, grid, shape);
    visit(row - 1, column, baseRow, baseColumn, grid, shape);
    visit(row, column + 1, baseRow, baseColumn, grid, shape);
    visit(row, column - 1, baseRow, baseColumn, grid, shape);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid) for (int &x : row) cin >> x;
    set<vector<pair<int, int>>> shapes;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j]) {
        vector<pair<int, int>> shape;
        visit(i, j, i, j, grid, shape);
        shapes.insert(shape);
    }
    cout << shapes.size() << '\n';
    return 0;
}


