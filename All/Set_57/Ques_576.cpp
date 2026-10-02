// Search a 2D Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, columns, target;
    cin >> rows >> columns;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (auto &row : matrix) for (int &value : row) cin >> value;
    cin >> target;
    int left = 0, right = rows * columns - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        int value = matrix[middle / columns][middle % columns];
        if (value == target) {
            cout << "true\n";
            return 0;
        }
        if (value < target) left = middle + 1;
        else right = middle - 1;
    }
    cout << "false\n";
    return 0;
}
