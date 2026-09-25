// Edit Distance

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> dp(b.size() + 1);
    iota(dp.begin(), dp.end(), 0);

    for (int i = 1; i <= (int)a.size(); i++) {
        int diagonal = dp[0];
        dp[0] = i;
        for (int j = 1; j <= (int)b.size(); j++) {
            int above = dp[j];
            if (a[i - 1] == b[j - 1]) dp[j] = diagonal;
            else dp[j] = 1 + min({dp[j], dp[j - 1], diagonal});
            diagonal = above;
        }
    }

    cout << dp[b.size()] << '\n';
    return 0;
}
