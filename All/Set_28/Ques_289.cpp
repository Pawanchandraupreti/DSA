// Minimum palindrome partition cuts

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;
    if (s.empty()) getline(cin, s);
    int n = (int)s.size();
    vector<vector<bool>> pal(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) pal[i][j] = true;
        }
    }

    vector<int> dp(n, INT_MAX / 2), parent(n, -1);
    for (int i = 0; i < n; ++i) {
        if (pal[0][i]) {
            dp[i] = 0;
            parent[i] = -1;
        } else {
            for (int j = 0; j < i; ++j) {
                if (pal[j + 1][i] && dp[j] + 1 < dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
    }

    cout << dp[n - 1];
    return 0;
}
