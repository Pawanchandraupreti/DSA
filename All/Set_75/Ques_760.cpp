// Regular Expression Matching

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;
    int n = text.size(), m = pattern.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true;
    for (int j = 2; j <= m; j++) if (pattern[j - 1] == '*') dp[0][j] = dp[0][j - 2];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (pattern[j - 1] == '.' || pattern[j - 1] == text[i - 1]) dp[i][j] = dp[i - 1][j - 1];
        else if (pattern[j - 1] == '*') {
            dp[i][j] = dp[i][j - 2];
            if (pattern[j - 2] == '.' || pattern[j - 2] == text[i - 1]) dp[i][j] = dp[i][j] || dp[i - 1][j];
        }
    }
    cout << (dp[n][m] ? "YES" : "NO") << '\n';
    return 0;
}
