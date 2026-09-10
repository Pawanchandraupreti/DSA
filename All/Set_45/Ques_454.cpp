// Decode Ways

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> dp(n + 1);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != '0') dp[i] += dp[i - 1];
        int x = stoi(s.substr(i - 2, 2));
        if (x >= 10 && x <= 26) dp[i] += dp[i - 2];
    }
    cout << (s[0] == '0' ? 0 : dp[n]);
    return 0;
}

