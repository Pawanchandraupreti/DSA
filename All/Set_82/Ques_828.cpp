// Minimum Difficulty Job Schedule

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, days;
    cin >> n >> days;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    if (n < days) { cout << -1 << '\n'; return 0; }
    const int inf = 1e9;
    vector<vector<int>> dp(days + 1, vector<int>(n + 1, inf));
    dp[0][0] = 0;
    for (int day = 1; day <= days; day++) for (int end = day; end <= n; end++) {
        int difficulty = 0;
        for (int start = end; start >= day; start--) {
            difficulty = max(difficulty, a[start - 1]);
            dp[day][end] = min(dp[day][end], dp[day - 1][start - 1] + difficulty);
        }
    }
    cout << dp[days][n] << '\n';
    return 0;
}
