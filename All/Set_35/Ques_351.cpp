// Find the longest common prefix among multiple strings

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(const vector<string>& words) {
    if (words.empty()) return "";

    string prefix = words[0];

    for (int i = 1; i < (int)words.size(); ++i) {
        while (words[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }

    return prefix;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << longestCommonPrefix(words);
    return 0;
}
