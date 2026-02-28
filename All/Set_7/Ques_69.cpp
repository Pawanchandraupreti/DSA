// Subset Sum (DP Table)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6, sum = 9;

    bool dp[7][10] = {false};

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= sum; s++) {
            if (arr[i - 1] <= s)
                dp[i][s] = dp[i - 1][s] || dp[i - 1][s - arr[i - 1]];
            else
                dp[i][s] = dp[i - 1][s];
        }
    }

    cout << (dp[n][sum] ? "Yes" : "No");
    return 0;
}