// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> dp(b.size() + 1);

    for (char x : a) {
        for (int j = b.size(); j >= 1; j--) {
            if (x == b[j - 1]) dp[j] = dp[j - 1] + 1;
            else dp[j] = max(dp[j], dp[j - 1]);
        }
    }
    cout << dp[b.size()] << '\n';
    return 0;
}
