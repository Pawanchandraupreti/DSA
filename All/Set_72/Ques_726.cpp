// Largest Divisible Subset Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n, 1);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) if (a[i] % a[j] == 0) dp[i] = max(dp[i], dp[j] + 1);
        answer = max(answer, dp[i]);
    }
    cout << answer << '\n';
    return 0;
}
