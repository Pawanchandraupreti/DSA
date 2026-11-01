// Number of Ways to Form Target

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, length;
    string target;
    cin >> n >> length;
    vector<string> words(n);
    for (string &word : words) cin >> word;
    cin >> target;
    const int mod = 1000000007;
    vector<vector<int>> count(length, vector<int>(26));
    for (auto &word : words) for (int i = 0; i < length; i++) count[i][word[i] - 'a']++;
    vector<long long> dp(target.size() + 1);
    dp[0] = 1;
    for (int column = 0; column < length; column++) for (int j = target.size(); j >= 1; j--) dp[j] = (dp[j] + dp[j - 1] * count[column][target[j - 1] - 'a']) % mod;
    cout << dp[target.size()] << '\n';
    return 0;
}
