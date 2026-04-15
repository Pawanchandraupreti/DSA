// Matrix Chain Multiplication (MCM)

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int arr[] = {10, 20, 30, 40};
    int n = 4;

    int dp[4][4] = {0};

    for(int len = 2; len < n; len++) {
        for(int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;

            dp[i][j] = 1e9;

            for(int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],
                               dp[i][k] + dp[k+1][j] +
                               arr[i-1]*arr[k]*arr[j]);
            }
        }
    }

    cout << dp[1][n-1];
}






