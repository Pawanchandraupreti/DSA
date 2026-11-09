// Longest Subsequence with Limited Difference

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int limit;
    cin >> s >> limit;
    vector<int> dp(26);
    int answer = 0;
    for (char ch : s) {
        int index = ch - 'a', best = 0;
        for (int i = max(0, index - limit); i <= min(25, index + limit); i++) best = max(best, dp[i]);
        dp[index] = best + 1;
        answer = max(answer, dp[index]);
    }
    cout << answer << '\n';
    return 0;
}
