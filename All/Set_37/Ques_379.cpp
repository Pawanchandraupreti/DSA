// Print the elements of a matrix in spiral order

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) {
        return result;
    }

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int column = left; column <= right; ++column) {
            result.push_back(matrix[top][column]);
        }
        ++top;

        for (int row = top; row <= bottom; ++row) {
            result.push_back(matrix[row][right]);
        }
        --right;

        if (top <= bottom) {
            for (int column = right; column >= left; --column) {
                result.push_back(matrix[bottom][column]);
            }
            --bottom;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                result.push_back(matrix[row][left]);
            }
            ++left;
        }
    }

    return result;
}

int main() {
    int rows, columns;
    cin >> rows >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (auto& row : matrix) {
        for (int& value : row) {
            cin >> value;
        }
    }

    for (int value : spiralOrder(matrix)) {
        cout << value << ' ';
    }

    return 0;
}
