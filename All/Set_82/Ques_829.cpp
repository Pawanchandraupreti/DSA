// Stone Game III Result

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n + 1);
    for (int &x : a) cin >> x;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = INT_MIN;
        int sum = 0;
        for (int take = 0; take < 3 && i + take < n; take++) {
            sum += a[i + take];
            dp[i] = max(dp[i], sum - dp[i + take + 1]);
        }
    }
    cout << (dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie") << '\n';
    return 0;
}
