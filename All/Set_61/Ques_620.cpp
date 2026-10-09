// Maximum Length of Repeated Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> first(n), second(m), dp(m + 1);
    for (int &value : first) cin >> value;
    for (int &value : second) cin >> value;
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (first[i - 1] == second[j - 1]) dp[j] = dp[j - 1] + 1;
            else dp[j] = 0;
            answer = max(answer, dp[j]);
        }
    }
    cout << answer << '\n';
    return 0;
}

