// Word Break

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;
    unordered_set<string> words;
    while (n--) {
        string w;
        cin >> w;
        words.insert(w);
    }

    int m = s.size();
    vector<bool> dp(m + 1);
    dp[0] = true;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && words.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    cout << (dp[m] ? "true" : "false");
    return 0;
}
