// Word Break

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }
    string text;
    cin >> text;
    vector<bool> possible(text.size() + 1);
    possible[0] = true;
    for (int end = 1; end <= (int)text.size(); end++) {
        for (int start = 0; start < end; start++) {
            if (possible[start] && words.count(text.substr(start, end - start))) {
                possible[end] = true;
                break;
            }
        }
    }
    cout << (possible.back() ? "true" : "false") << '\n';
    return 0;
}


