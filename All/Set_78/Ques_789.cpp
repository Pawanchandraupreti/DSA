// Minimum Falling Path Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) cin >> dp[i];
    for (int row = 1; row < n; row++) {
        vector<int> next(n);
        for (int column = 0; column < n; column++) {
            int best = dp[column];
            if (column) best = min(best, dp[column - 1]);
            if (column + 1 < n) best = min(best, dp[column + 1]);
            cin >> next[column];
            next[column] += best;
        }
        dp = next;
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
