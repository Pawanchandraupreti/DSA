// Matrix Transpose

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (auto &row : matrix) for (int &value : row) cin >> value;
    for (int column = 0; column < columns; column++) {
        for (int row = 0; row < rows; row++) cout << matrix[row][column] << ' ';
        cout << '\n';
    }
    return 0;
}
