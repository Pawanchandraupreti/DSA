// Digit DP Counting Numbers

#include <bits/stdc++.h>
using namespace std;

long long dp[20][2][2];
string num;

long long solve(int pos, int tight, int started) {
    if (pos == (int)num.length()) {
        return started;
    }

    if (dp[pos][tight][started] != -1) {
        return dp[pos][tight][started];
    }

    int limit = tight ? (num[pos] - '0') : 9;
    long long result = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        int newTight = tight && (digit == limit) ? 1 : 0;
        int newStarted = started || (digit > 0) ? 1 : 0;
        result += solve(pos + 1, newTight, newStarted);
    }

    return dp[pos][tight][started] = result;
}

int main() {
    cin >> num;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1, 0);
    return 0;
}


