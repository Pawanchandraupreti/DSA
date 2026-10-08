// Edit Distance

#include <bits/stdc++.h>
using namespace std;

int main() {
    string first, second;
    cin >> first >> second;
    vector<int> dp(second.size() + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 1; i <= (int)first.size(); i++) {
        int diagonal = dp[0];
        dp[0] = i;
        for (int j = 1; j <= (int)second.size(); j++) {
            int previous = dp[j];
            if (first[i - 1] == second[j - 1]) dp[j] = diagonal;
            else dp[j] = 1 + min({dp[j], dp[j - 1], diagonal});
            diagonal = previous;
        }
    }
    cout << dp.back() << '\n';
    return 0;
}
