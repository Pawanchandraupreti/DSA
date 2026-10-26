// Maximum Sum Rectangle

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row : a) for (int &x : row) cin >> x;
    int answer = INT_MIN;
    for (int left = 0; left < m; left++) {
        vector<int> sums(n);
        for (int right = left; right < m; right++) {
            for (int row = 0; row < n; row++) sums[row] += a[row][right];
            int current = 0;
            for (int value : sums) {
                current = max(value, current + value);
                answer = max(answer, current);
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
