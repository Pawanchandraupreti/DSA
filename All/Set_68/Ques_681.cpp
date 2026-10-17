// Maximum Sum Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n);
    for (int &x : a) cin >> x;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = a[i];
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
        answer = max(answer, dp[i]);
    }
    cout << answer << '\n';
    return 0;
}
