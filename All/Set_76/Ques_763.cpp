// Word Pattern Matching

#include <bits/stdc++.h>
using namespace std;

int main() {
    string pattern, text, word;
    cin >> pattern;
    getline(cin, text);
    stringstream stream(text);
    vector<string> words;
    while (stream >> word) words.push_back(word);
    if (pattern.size() != words.size()) {
        cout << "NO\n";
        return 0;
    }
    unordered_map<char, string> letters;
    unordered_map<string, char> values;
    for (int i = 0; i < (int)pattern.size(); i++) {
        if ((letters.count(pattern[i]) && letters[pattern[i]] != words[i]) || (values.count(words[i]) && values[words[i]] != pattern[i])) {
            cout << "NO\n";
            return 0;
        }
        letters[pattern[i]] = words[i];
        values[words[i]] = pattern[i];
    }
    cout << "YES\n";
    return 0;
}


