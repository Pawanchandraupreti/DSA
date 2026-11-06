// Longest Palindromic Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> dp(s.size());
    for (int left = s.size() - 1; left >= 0; left--) {
        dp[left] = 1;
        int diagonal = 0;
        for (int right = left + 1; right < (int)s.size(); right++) {
            int old = dp[right];
            if (s[left] == s[right]) dp[right] = diagonal + 2;
            else dp[right] = max(dp[right], dp[right - 1]);
            diagonal = old;
        }
    }
    cout << (s.empty() ? 0 : dp.back()) << '\n';
    return 0;
}
