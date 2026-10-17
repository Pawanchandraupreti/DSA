// Search a Sorted Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, target;
    cin >> n >> m >> target;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (auto &row : matrix) for (int &x : row) cin >> x;

    int row = 0, column = m - 1;
    while (row < n && column >= 0) {
        if (matrix[row][column] == target) {
            cout << row << ' ' << column << '\n';
            return 0;
        }
        if (matrix[row][column] > target) column--;
        else row++;
    }
    cout << "-1 -1\n";
    return 0;
}
