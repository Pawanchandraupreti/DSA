// Partition Equal Subset Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for (int &x : a) {
        cin >> x;
        total += x;
    }

    if (total % 2) {
        cout << "false\n";
        return 0;
    }

    int target = total / 2;
    vector<bool> dp(target + 1);
    dp[0] = true;
    for (int x : a) {
        for (int sum = target; sum >= x; sum--) dp[sum] = dp[sum] || dp[sum - x];
    }

    cout << (dp[target] ? "true" : "false") << '\n';
    return 0;
}
