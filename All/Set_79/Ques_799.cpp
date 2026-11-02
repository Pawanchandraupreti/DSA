// Longest Arithmetic Subsequence

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<unordered_map<int, int>> dp(n);
    int answer = n ? 1 : 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
        int difference = a[i] - a[j];
        dp[i][difference] = max(dp[i][difference], dp[j].count(difference) ? dp[j][difference] + 1 : 2);
        answer = max(answer, dp[i][difference]);
    }
    cout << answer << '\n';
    return 0;
}
