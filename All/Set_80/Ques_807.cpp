// Maximum Submatrix Sum Not Exceeding K

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, limit;
    cin >> n >> m >> limit;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row : a) for (int &x : row) cin >> x;
    int answer = INT_MIN;
    for (int left = 0; left < m; left++) {
        vector<int> sums(n);
        for (int right = left; right < m; right++) {
            for (int i = 0; i < n; i++) sums[i] += a[i][right];
            for (int top = 0; top < n; top++) {
                int current = 0;
                for (int bottom = top; bottom < n; bottom++) {
                    current += sums[bottom];
                    if (current <= limit) answer = max(answer, current);
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
