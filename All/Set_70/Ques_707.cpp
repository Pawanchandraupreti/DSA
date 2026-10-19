// Minimum Triangle Path Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n);
    for (int row = 0; row < n; row++) {
        vector<int> current(row + 1);
        for (int &x : current) cin >> x;
        for (int j = row; j >= 0; j--) {
            if (row == 0) dp[j] = current[j];
            else if (j == 0) dp[j] += current[j];
            else if (j == row) dp[j] = dp[j - 1] + current[j];
            else dp[j] = min(dp[j - 1], dp[j]) + current[j];
        }
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
