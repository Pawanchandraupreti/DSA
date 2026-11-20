// Transpose of a Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row : a) for (int &x : row) cin >> x;
    for (int c = 0; c < m; c++) {
        for (int r = 0; r < n; r++) cout << a[r][c] << ' ';
        cout << '\n';
    }
    return 0;
}