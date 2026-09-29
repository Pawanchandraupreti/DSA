// Number of Islands

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<string> grid(rows);
    for (string &row : grid) cin >> row;
    int islands = 0;
    int directions[5] = {-1, 0, 1, 0, -1};
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            if (grid[row][column] != '1') continue;
            islands++;
            queue<pair<int, int>> pending;
            pending.push({row, column});
            grid[row][column] = '0';
            while (!pending.empty()) {
                auto [currentRow, currentColumn] = pending.front();
                pending.pop();
                for (int direction = 0; direction < 4; direction++) {
                    int nextRow = currentRow + directions[direction];
                    int nextColumn = currentColumn + directions[direction + 1];
                    if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 && nextColumn < columns && grid[nextRow][nextColumn] == '1') {
                        grid[nextRow][nextColumn] = '0';
                        pending.push({nextRow, nextColumn});
                    }
                }
            }
        }
    }
    cout << islands << '\n';
    return 0;
}

