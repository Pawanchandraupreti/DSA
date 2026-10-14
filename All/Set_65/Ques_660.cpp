// Partition Equal Subset Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, total = 0;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        total += x;
    }
    if (total % 2) {
        cout << "NO\n";
        return 0;
    }

    vector<bool> dp(total / 2 + 1);
    dp[0] = true;
    for (int x : a) {
        for (int sum = total / 2; sum >= x; sum--) dp[sum] = dp[sum] || dp[sum - x];
    }
    cout << (dp[total / 2] ? "YES" : "NO") << '\n';
    return 0;
}
