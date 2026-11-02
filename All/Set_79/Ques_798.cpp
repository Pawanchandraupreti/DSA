// Number of Dice Rolls with Target Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int dice, faces, target;
    cin >> dice >> faces >> target;
    const int mod = 1000000007;
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 0; i < dice; i++) {
        vector<int> next(target + 1);
        for (int sum = 0; sum <= target; sum++) for (int face = 1; face <= faces && sum + face <= target; face++) next[sum + face] = (next[sum + face] + dp[sum]) % mod;
        dp = next;
    }
    cout << dp[target] << '\n';
    return 0;
}
