// Partition Equal Subset Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int& x : a) {
        cin >> x;
        sum += x;
    }
    if (sum % 2) {
        cout << "false";
        return 0;
    }

    vector<bool> dp(sum / 2 + 1);
    dp[0] = true;
    for (int x : a) {
        for (int j = sum / 2; j >= x; j--) dp[j] = dp[j] || dp[j - x];
    }
    cout << (dp[sum / 2] ? "true" : "false");
    return 0;
}
