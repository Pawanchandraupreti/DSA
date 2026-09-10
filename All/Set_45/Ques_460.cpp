// Longest Palindromic Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n, 1);

    for (int i = n - 2; i >= 0; i--) {
        int prev = 0;
        for (int j = i + 1; j < n; j++) {
            int old = dp[j];
            if (s[i] == s[j]) dp[j] = prev + 2;
            else dp[j] = max(dp[j], dp[j - 1]);
            prev = old;
        }
    }
    cout << dp[n - 1];
    return 0;
}


