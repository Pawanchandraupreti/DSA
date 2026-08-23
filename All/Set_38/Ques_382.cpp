// Word Ladder

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) {
        return 0;
    }

    queue<string> q;
    q.push(beginWord);
    int steps = 1;

    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            string current = q.front();
            q.pop();

            if (current == endWord) {
                return steps;
            }

            for (int j = 0; j < (int)current.size(); ++j) {
                char original = current[j];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == original) continue;
                    current[j] = c;
                    if (dict.count(current)) {
                        q.push(current);
                        dict.erase(current);
                    }
                }
                current[j] = original;
            }
        }
        ++steps;
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    string beginWord, endWord;
    cin >> beginWord >> endWord;

    vector<string> wordList(n);
    for (int i = 0; i < n; ++i) {
        cin >> wordList[i];
    }

    cout << ladderLength(beginWord, endWord, wordList);
    return 0;
}


