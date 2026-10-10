// Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> last;
    int ans = 0, left = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (last.count(s[i])) left = max(left, last[s[i]] + 1);
        last[s[i]] = i;
        ans = max(ans, i - left + 1);
    }
    cout << ans << '\n';
    return 0;
}
