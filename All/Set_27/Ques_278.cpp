// Count subsets with sum S (mod 1e9+7)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll MOD = 1000000007LL;

int main() {

    int n, S;
    if (!(cin >> n >> S)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> dp(S + 1, 0);
    dp[0] = 1;

    for (int x : a) {
        for (int s = S; s >= x; --s) {
            dp[s] = (dp[s] + dp[s - x]) % MOD;
        }
    }

    cout << dp[S];
    return 0;
}

