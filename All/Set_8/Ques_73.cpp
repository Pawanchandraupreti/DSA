// Partition Equal Subset Sum

#include <iostream>
using namespace std;

int main() {
    int nums[] = {1, 5, 11, 5};
    int n = 4;

    int total = 0;
    for (int i = 0; i < n; i++)
        total += nums[i];

    if (total % 2 != 0) {
        cout << "No";
        return 0;
    }

    int target = total / 2;

    bool dp[5][12] = {false};

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= target; s++) {
            if (nums[i - 1] <= s)
                dp[i][s] = dp[i - 1][s] || dp[i - 1][s - nums[i - 1]];
            else
                dp[i][s] = dp[i - 1][s];
        }
    }

    cout << (dp[n][target] ? "Yes" : "No");
    return 0;
}


