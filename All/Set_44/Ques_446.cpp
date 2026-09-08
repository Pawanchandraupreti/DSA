// Rotate Matrix 90 Degrees

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto& row : a) for (int& x : row) cin >> x;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) swap(a[i][j], a[j][i]);
    }
    for (auto& row : a) reverse(row.begin(), row.end());

    for (auto& row : a) {
        for (int x : row) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}

