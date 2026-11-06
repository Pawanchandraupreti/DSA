// Count Square Submatrices of Ones

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int diagonal = 0;
        for (int j = 1; j <= m; j++) {
            int cell;
            cin >> cell;
            int old = dp[j];
            if (cell) dp[j] = min({dp[j], dp[j - 1], diagonal}) + 1;
            else dp[j] = 0;
            answer += dp[j];
            diagonal = old;
        }
    }
    cout << answer << '\n';
    return 0;
}
