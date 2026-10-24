// Interleaving String

#include <bits/stdc++.h>
using namespace std;

int main() {
    string first, second, target;
    cin >> first >> second >> target;
    if (first.size() + second.size() != target.size()) {
        cout << "NO\n";
        return 0;
    }
    vector<bool> dp(second.size() + 1);
    dp[0] = true;
    for (int j = 1; j <= (int)second.size(); j++) dp[j] = dp[j - 1] && second[j - 1] == target[j - 1];
    for (int i = 1; i <= (int)first.size(); i++) {
        dp[0] = dp[0] && first[i - 1] == target[i - 1];
        for (int j = 1; j <= (int)second.size(); j++) dp[j] = (dp[j] && first[i - 1] == target[i + j - 1]) || (dp[j - 1] && second[j - 1] == target[i + j - 1]);
    }
    cout << (dp.back() ? "YES" : "NO") << '\n';
    return 0;
}
