// Word Break

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;
    unordered_set<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }

    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= (int)s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && words.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    cout << (dp[s.size()] ? "true" : "false") << '\n';
    return 0;
}
