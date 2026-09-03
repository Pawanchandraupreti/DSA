// Traveling Salesperson Problem with Bitmask DP

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (auto& row : cost) for (int& value : row) cin >> value;

    const int infinity = 1e9;
    int fullMask = 1 << n;
    vector<vector<int>> dp(fullMask, vector<int>(n, infinity));
    dp[1][0] = 0;

    for (int mask = 1; mask < fullMask; ++mask) {
        for (int last = 0; last < n; ++last) {
            if (!(mask & (1 << last)) || dp[mask][last] == infinity) continue;
            for (int next = 0; next < n; ++next) {
                if (!(mask & (1 << next))) {
                    int newMask = mask | (1 << next);
                    dp[newMask][next] = min(dp[newMask][next], dp[mask][last] + cost[last][next]);
                }
            }
        }
    }

    int answer = infinity;
    for (int last = 1; last < n; ++last) {
        answer = min(answer, dp[fullMask - 1][last] + cost[last][0]);
    }
    cout << (n == 1 ? 0 : answer);
    return 0;
}
