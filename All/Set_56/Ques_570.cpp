// Flood Fill

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, columns, startRow, startColumn, newColor;
    cin >> rows >> columns;
    vector<vector<int>> image(rows, vector<int>(columns));
    for (auto &row : image) for (int &value : row) cin >> value;
    cin >> startRow >> startColumn >> newColor;
    int oldColor = image[startRow][startColumn];
    if (oldColor != newColor) {
        queue<pair<int, int>> pending;
        pending.push({startRow, startColumn});
        image[startRow][startColumn] = newColor;
        int directions[5] = {-1, 0, 1, 0, -1};
        while (!pending.empty()) {
            auto [row, column] = pending.front();
            pending.pop();
            for (int direction = 0; direction < 4; direction++) {
                int nextRow = row + directions[direction];
                int nextColumn = column + directions[direction + 1];
                if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 && nextColumn < columns && image[nextRow][nextColumn] == oldColor) {
                    image[nextRow][nextColumn] = newColor;
                    pending.push({nextRow, nextColumn});
                }
            }
        }
    }
    for (auto &row : image) {
        for (int value : row) cout << value << ' ';
        cout << '\n';
    }
    return 0;
}

