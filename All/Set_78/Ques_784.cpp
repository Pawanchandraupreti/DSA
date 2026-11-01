// Minimum Deletions to Make Strings Equal

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> dp(b.size() + 1);
    for (char x : a) for (int j = b.size(); j >= 1; j--) if (x == b[j - 1]) dp[j] = dp[j - 1] + 1; else dp[j] = max(dp[j], dp[j - 1]);
    cout << a.size() + b.size() - 2 * dp.back() << '\n';
    return 0;
}
