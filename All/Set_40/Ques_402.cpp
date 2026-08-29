// Trapping Rain Water II

#include <bits/stdc++.h>
using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.empty() || heightMap[0].empty()) return 0;

    int rows = (int)heightMap.size();
    int columns = (int)heightMap[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
    vector<vector<bool>> visited(rows, vector<bool>(columns, false));

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (row == 0 || row == rows - 1 || column == 0 || column == columns - 1) {
                heap.push({heightMap[row][column], {row, column}});
                visited[row][column] = true;
            }
        }
    }

    int waterLevel = 0;
    int trapped = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!heap.empty()) {
        auto [height, pos] = heap.top();
        heap.pop();
        auto [row, column] = pos;
        waterLevel = max(waterLevel, height);

        for (auto [dRow, dColumn] : directions) {
            int newRow = row + dRow;
            int newColumn = column + dColumn;

            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && !visited[newRow][newColumn]) {
                visited[newRow][newColumn] = true;
                trapped += max(0, waterLevel - heightMap[newRow][newColumn]);
                heap.push({heightMap[newRow][newColumn], {newRow, newColumn}});
            }
        }
    }

    return trapped;
}

int main() {
    int rows, columns;
    cin >> rows >> columns;

    vector<vector<int>> heightMap(rows, vector<int>(columns));
    for (auto& row : heightMap) {
        for (int& height : row) cin >> height;
    }

    cout << trapRainWater(heightMap);
    return 0;
}
