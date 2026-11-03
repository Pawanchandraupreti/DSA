// Count Good Strings

#include <bits/stdc++.h>
using namespace std;

int main() {
    int low, high, zero, one;
    cin >> low >> high >> zero >> one;
    const int mod = 1000000007;
    vector<int> dp(high + 1);
    dp[0] = 1;
    long long answer = 0;
    for (int length = 1; length <= high; length++) {
        if (length >= zero) dp[length] = (dp[length] + dp[length - zero]) % mod;
        if (length >= one) dp[length] = (dp[length] + dp[length - one]) % mod;
        if (length >= low) answer = (answer + dp[length]) % mod;
    }
    cout << answer << '\n';
    return 0;
}
