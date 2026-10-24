// Minimum Deletions to Make Strings Equal

#include <bits/stdc++.h>
using namespace std;

int main() {
    string first, second;
    cin >> first >> second;
    vector<int> dp(second.size() + 1);
    for (int i = 1; i <= (int)first.size(); i++) {
        int diagonal = 0;
        for (int j = 1; j <= (int)second.size(); j++) {
            int old = dp[j];
            if (first[i - 1] == second[j - 1]) dp[j] = diagonal + 1;
            else dp[j] = max(dp[j], dp[j - 1]);
            diagonal = old;
        }
    }
    int common = dp.back();
    cout << first.size() + second.size() - 2 * common << '\n';
    return 0;
}
