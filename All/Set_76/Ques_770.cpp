// Minimum Cost to Paint Houses

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(3);
    cin >> dp[0] >> dp[1] >> dp[2];
    for (int i = 1; i < n; i++) {
        int red, blue, green;
        cin >> red >> blue >> green;
        vector<int> next = {red + min(dp[1], dp[2]), blue + min(dp[0], dp[2]), green + min(dp[0], dp[1])};
        dp = next;
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
