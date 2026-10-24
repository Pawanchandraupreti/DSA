// Palindrome Partition Count

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int right = 0; right < n; right++) {
        for (int left = 0; left <= right; left++) {
            bool palindrome = true;
            for (int i = left, j = right; i < j; i++, j--) if (s[i] != s[j]) palindrome = false;
            if (palindrome) dp[right + 1] += dp[left];
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
