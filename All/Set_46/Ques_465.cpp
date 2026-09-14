// Combination Sum IV

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<long long> dp(target + 1);
    dp[0] = 1;
    for (int sum = 1; sum <= target; sum++) {
        for (int x : a) if (x <= sum) dp[sum] += dp[sum - x];
    }
    cout << dp[target];
    return 0;
}
