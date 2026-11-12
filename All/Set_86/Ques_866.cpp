// Transpose Matrix

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row : a) for (int &x : row) cin >> x;
    for (int column = 0; column < m; column++) {
        for (int row = 0; row < n; row++) cout << a[row][column] << ' ';
        cout << '\n';
    }
    return 0;
}
