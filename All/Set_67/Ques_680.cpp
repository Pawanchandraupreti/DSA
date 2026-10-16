// Number of Distinct Subsequences

#include <bits/stdc++.h>
using namespace std;

int main() {
    string source, target;
    cin >> source >> target;
    vector<long long> dp(target.size() + 1);
    dp[0] = 1;

    for (char ch : source) {
        for (int j = target.size(); j >= 1; j--) {
            if (ch == target[j - 1]) dp[j] += dp[j - 1];
        }
    }
    cout << dp[target.size()] << '\n';
    return 0;
}
