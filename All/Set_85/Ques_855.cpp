// Diagonal Matrix Traversal

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row : a) for (int &x : row) cin >> x;
    for (int sum = 0; sum < n + m - 1; sum++) {
        if (sum % 2 == 0) {
            for (int row = min(n - 1, sum); row >= 0 && sum - row < m; row--) cout << a[row][sum - row] << ' ';
        } else {
            for (int row = max(0, sum - m + 1); row < n && sum - row >= 0; row++) cout << a[row][sum - row] << ' ';
        }
    }
    cout << '\n';
    return 0;
}
