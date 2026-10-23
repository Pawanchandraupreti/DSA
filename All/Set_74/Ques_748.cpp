// Stone Game II Maximum Stones

#include <bits/stdc++.h>
using namespace std;

int solve(int index, int power, const vector<int> &suffix, vector<vector<int>> &dp) {
    if (index >= (int)suffix.size() - 1) return 0;
    if (dp[index][power] != -1) return dp[index][power];
    int answer = 0;
    for (int take = 1; take <= 2 * power && index + take < (int)suffix.size(); take++) {
        answer = max(answer, suffix[index] - solve(index + take, max(power, take), suffix, dp));
    }
    return dp[index][power] = answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> piles(n), suffix(n + 1);
    for (int &x : piles) cin >> x;
    for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << solve(0, 1, suffix, dp) << '\n';
    return 0;
}
