// Predict the Winner

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), dp;
    for (int &x : a) cin >> x;
    dp = a;
    for (int length = 2; length <= n; length++) {
        for (int left = 0; left + length <= n; left++) {
            int right = left + length - 1;
            dp[left] = max(a[left] - dp[left + 1], a[right] - dp[left]);
        }
    }
    cout << (dp[0] >= 0 ? "YES" : "NO") << '\n';
    return 0;
}
