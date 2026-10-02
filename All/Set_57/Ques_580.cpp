// Minimum Path Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> grid(rows, vector<int>(columns));
    for (auto &row : grid) for (int &value : row) cin >> value;
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            if (row == 0 && column == 0) continue;
            int fromTop = row ? grid[row - 1][column] : INT_MAX;
            int fromLeft = column ? grid[row][column - 1] : INT_MAX;
            grid[row][column] += min(fromTop, fromLeft);
        }
    }
    cout << grid[rows - 1][columns - 1] << '\n';
    return 0;
}
