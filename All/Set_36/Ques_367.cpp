// Rotate a square matrix 90 degrees clockwise

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    rotateMatrix(matrix);

    for (const vector<int>& row : matrix) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << '\n';
    }

    return 0;
}
