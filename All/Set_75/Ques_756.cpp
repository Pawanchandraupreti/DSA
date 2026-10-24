// Perfect Squares Minimum Count

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int sum = 1; sum <= n; sum++) {
        for (int square = 1; square * square <= sum; square++) dp[sum] = min(dp[sum], dp[sum - square * square] + 1);
    }
    cout << dp[n] << '\n';
    return 0;
}
