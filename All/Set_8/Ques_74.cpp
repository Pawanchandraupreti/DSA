// Matrix DP – Unique Paths

#include <iostream>
using namespace std;

int main() {
    int m = 3, n = 3;

    int dp[4][4] = {0};

    for (int i = 1; i <= m; i++)
        dp[i][1] = 1;

    for (int j = 1; j <= n; j++)
        dp[1][j] = 1;

    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    cout << dp[m][n];
    return 0;
}
