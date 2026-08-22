// Burst Balloons

#include <bits/stdc++.h>
using namespace std;

int maxCoins(const vector<int>& balloons) {
    int balloonCount = (int)balloons.size();
    vector<int> values(balloonCount + 2, 1);
    for (int index = 0; index < balloonCount; ++index) {
        values[index + 1] = balloons[index];
    }

    vector<vector<int>> dp(balloonCount + 2, vector<int>(balloonCount + 2, 0));

    for (int intervalLength = 1; intervalLength <= balloonCount; ++intervalLength) {
        for (int left = 1; left + intervalLength - 1 <= balloonCount; ++left) {
            int right = left + intervalLength - 1;
            for (int last = left; last <= right; ++last) {
                int coins = values[left - 1] * values[last] * values[right + 1];
                coins += dp[left][last - 1] + dp[last + 1][right];
                dp[left][right] = max(dp[left][right], coins);
            }
        }
    }

    return dp[1][balloonCount];
}

int main() {
    int n;
    cin >> n;

    vector<int> balloons(n);
    for (int& balloon : balloons) {
        cin >> balloon;
    }

    cout << maxCoins(balloons);
    return 0;
}
