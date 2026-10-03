// Rotate Image

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (auto &row : matrix) for (int &value : row) cin >> value;
    reverse(matrix.begin(), matrix.end());
    for (int row = 0; row < n; row++) {
        for (int column = row + 1; column < n; column++) swap(matrix[row][column], matrix[column][row]);
    }
    for (auto &row : matrix) {
        for (int value : row) cout << value << ' ';
        cout << '\n';
    }
    return 0;
}
