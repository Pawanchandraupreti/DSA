// Aho-Corasick Multiple Pattern Matching

#include <bits/stdc++.h>
using namespace std;

struct Node {
    array<int, 26> next{};
    int failure = 0;
    vector<int> output;
    Node() { next.fill(-1); }
};

int main() {
    int patternCount;
    cin >> patternCount;
    vector<Node> trie(1);
    for (int pattern = 0; pattern < patternCount; ++pattern) {
        string word;
        cin >> word;
        int vertex = 0;
        for (char letter : word) {
            int value = letter - 'a';
            if (trie[vertex].next[value] == -1) {
                trie[vertex].next[value] = (int)trie.size();
                trie.emplace_back();
            }
            vertex = trie[vertex].next[value];
        }
        trie[vertex].output.push_back(pattern);
    }

    queue<int> pending;
    for (int value = 0; value < 26; ++value) {
        int child = trie[0].next[value];
        if (child == -1) trie[0].next[value] = 0;
        else pending.push(child);
    }
    while (!pending.empty()) {
        int vertex = pending.front();
        pending.pop();
        for (int value = 0; value < 26; ++value) {
            int child = trie[vertex].next[value];
            if (child == -1) trie[vertex].next[value] = trie[trie[vertex].failure].next[value];
            else {
                trie[child].failure = trie[trie[vertex].failure].next[value];
                for (int index : trie[trie[child].failure].output) trie[child].output.push_back(index);
                pending.push(child);
            }
        }
    }

    string text;
    cin >> text;
    vector<int> occurrences(patternCount, 0);
    int vertex = 0;
    for (char letter : text) {
        vertex = trie[vertex].next[letter - 'a'];
        for (int pattern : trie[vertex].output) ++occurrences[pattern];
    }
    for (int count : occurrences) cout << count << ' ';
    return 0;
}
