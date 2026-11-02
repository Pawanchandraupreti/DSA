// Count Vowel Permutations

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const long long mod = 1000000007;
    vector<long long> dp(5, 1);
    for (int length = 1; length < n; length++) {
        vector<long long> next = {(dp[1] + dp[2] + dp[4]) % mod, (dp[0] + dp[2]) % mod, (dp[1] + dp[3]) % mod, (dp[2]) % mod, (dp[2] + dp[3]) % mod};
        dp = next;
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) % mod << '\n';
    return 0;
}
