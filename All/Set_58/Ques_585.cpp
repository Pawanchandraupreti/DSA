// Spiral Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (auto &row : matrix) for (int &value : row) cin >> value;
    int top = 0, bottom = rows - 1, left = 0, right = columns - 1;
    while (top <= bottom && left <= right) {
        for (int column = left; column <= right; column++) cout << matrix[top][column] << ' ';
        top++;
        for (int row = top; row <= bottom; row++) cout << matrix[row][right] << ' ';
        right--;
        if (top <= bottom) for (int column = right; column >= left; column--) cout << matrix[bottom][column] << ' ';
        bottom--;
        if (left <= right) for (int row = bottom; row >= top; row--) cout << matrix[row][left] << ' ';
        left++;
    }
    cout << '\n';
    return 0;
}
