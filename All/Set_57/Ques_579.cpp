// Word Pattern

#include <bits/stdc++.h>
using namespace std;

int main() {
    string pattern, text;
    cin >> pattern >> text;
    unordered_map<char, char> mapping;
    unordered_set<char> used;
    if (pattern.size() != text.size()) {
        cout << "false\n";
        return 0;
    }
    for (int i = 0; i < (int)pattern.size(); i++) {
        if (mapping.count(pattern[i])) {
            if (mapping[pattern[i]] != text[i]) {
                cout << "false\n";
                return 0;
            }
        } else {
            if (used.count(text[i])) {
                cout << "false\n";
                return 0;
            }
            mapping[pattern[i]] = text[i];
            used.insert(text[i]);
        }
    }
    cout << "true\n";
    return 0;
}
