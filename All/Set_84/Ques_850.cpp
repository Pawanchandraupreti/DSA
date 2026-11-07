// Longest Ideal Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<int> dp(26);
    int answer = 0;
    for (char ch : s) {
        int current = 1;
        for (int i = max(0, ch - 'a' - k); i <= min(25, ch - 'a' + k); i++) current = max(current, dp[i] + 1);
        dp[ch - 'a'] = max(dp[ch - 'a'], current);
        answer = max(answer, dp[ch - 'a']);
    }
    cout << answer << '\n';
    return 0;
}
