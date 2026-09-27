// Combination Sum IV

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;
    cin >> target;

    vector<long long> dp(target + 1);
    dp[0] = 1;
    for (int sum = 1; sum <= target; sum++) {
        for (int x : nums) {
            if (x <= sum) dp[sum] += dp[sum - x];
        }
    }

    cout << dp[target] << '\n';
    return 0;
}
