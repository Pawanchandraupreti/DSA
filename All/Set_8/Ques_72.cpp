// Longest Common Subsequence (LCS)

#include <iostream>
using namespace std;

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    int n = s1.length();
    int m = s2.length();

    int dp[6][4] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m];
    return 0;
}