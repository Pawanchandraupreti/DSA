// Combination Sum IV

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> numbers(n), dp(target + 1);
    for (int &value : numbers) cin >> value;
    dp[0] = 1;
    for (int sum = 1; sum <= target; sum++) {
        for (int value : numbers) {
            if (value <= sum) dp[sum] += dp[sum - value];
        }
    }
    cout << dp[target] << '\n';
    return 0;
}
