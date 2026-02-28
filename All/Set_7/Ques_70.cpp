// Longest Increasing Subsequence (O(n²) DP)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10,9,2,5,3,7,101,18};
    int n = 8;

    int dp[8];
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        maxLen = max(maxLen, dp[i]);
    }

    cout << maxLen;
    return 0;
}