// Longest Common Subsequence Reconstruction

#include <bits/stdc++.h>
using namespace std;

int main() {
    string first, second;
    cin >> first >> second;
    int n = (int)first.size(), m = (int)second.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (first[i - 1] == second[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string result;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (first[i - 1] == second[j - 1]) {
            result.push_back(first[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(result.begin(), result.end());
    cout << result.length() << '\n' << result;
    return 0;
}
