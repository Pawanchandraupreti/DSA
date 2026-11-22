// Group Anagrams

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, vector<string>> groups;
    while (n--) {
        string s, key;
        cin >> s;
        key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    for (auto &[key, words] : groups) {
        for (string &s : words) cout << s << ' ';
        cout << '\n';
    }
    return 0;
}


