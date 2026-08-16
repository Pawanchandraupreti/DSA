// Longest palindromic substring

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(const string& s) {
    if (s.empty()) return "";

    int start = 0, maxLen = 1;
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i + length - 1 < n; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j] && (length == 3 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (length > maxLen || (length == maxLen && i < start)) {
                    start = i;
                    maxLen = length;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}
