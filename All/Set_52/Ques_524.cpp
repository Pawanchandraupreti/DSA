// Group Anagrams

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, vector<string>> groups;
    for (int i = 0; i < n; i++) {
        string word, key;
        cin >> word;
        key = word;
        sort(key.begin(), key.end());
        groups[key].push_back(word);
    }

    for (auto &group : groups) {
        for (string &word : group.second) cout << word << ' ';
        cout << '\n';
    }
    return 0;
}
