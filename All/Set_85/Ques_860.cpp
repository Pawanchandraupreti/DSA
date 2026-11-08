// Longest Common Substring Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> dp(b.size() + 1);
    int answer = 0;
    for (char x : a) {
        for (int j = b.size(); j >= 1; j--) {
            if (x == b[j - 1]) dp[j] = dp[j - 1] + 1;
            else dp[j] = 0;
            answer = max(answer, dp[j]);
        }
    }
    cout << answer << '\n';
    return 0;
}
