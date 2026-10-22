// Ways to Stay at Same Place

#include <bits/stdc++.h>
using namespace std;

int main() {
    int steps, length;
    cin >> steps >> length;
    const int mod = 1000000007;
    length = min(length, steps + 1);
    vector<int> dp(length);
    dp[0] = 1;
    for (int step = 0; step < steps; step++) {
        vector<int> next(length);
        for (int position = 0; position < length; position++) {
            next[position] = dp[position];
            if (position > 0) next[position] = (next[position] + dp[position - 1]) % mod;
            if (position + 1 < length) next[position] = (next[position] + dp[position + 1]) % mod;
        }
        dp = move(next);
    }
    cout << dp[0] << '\n';
    return 0;
}
