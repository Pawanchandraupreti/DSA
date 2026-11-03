// Longest String Chain

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (string &word : words) cin >> word;
    sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    unordered_map<string, int> dp;
    int answer = 0;
    for (string word : words) {
        dp[word] = 1;
        for (int i = 0; i < (int)word.size(); i++) {
            string previous = word.substr(0, i) + word.substr(i + 1);
            dp[word] = max(dp[word], dp[previous] + 1);
        }
        answer = max(answer, dp[word]);
    }
    cout << answer << '\n';
    return 0;
}
