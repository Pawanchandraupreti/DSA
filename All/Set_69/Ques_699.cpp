// Word Ladder Length

#include <bits/stdc++.h>
using namespace std;

int main() {
    string begin, finish;
    int n;
    cin >> begin >> finish >> n;
    unordered_set<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }

    queue<pair<string, int>> q;
    q.push({begin, 1});
    while (!q.empty()) {
        auto [word, steps] = q.front();
        q.pop();
        if (word == finish) {
            cout << steps << '\n';
            return 0;
        }
        for (int i = 0; i < (int)word.size(); i++) {
            string next = word;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                next[i] = ch;
                if (words.count(next)) {
                    words.erase(next);
                    q.push({next, steps + 1});
                }
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}
