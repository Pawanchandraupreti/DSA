// Multiple Pattern Matching with Aho-Corasick

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26]{};
    int link = 0;
    vector<int> patterns;
};

int main() {
    int patternCount;
    cin >> patternCount;
    vector<Node> trie(1);
    for (int id = 0; id < patternCount; id++) {
        string pattern;
        cin >> pattern;
        int vertex = 0;
        for (char ch : pattern) {
            int letter = ch - 'a';
            if (!trie[vertex].next[letter]) {
                trie[vertex].next[letter] = trie.size();
                trie.push_back(Node());
            }
            vertex = trie[vertex].next[letter];
        }
        trie[vertex].patterns.push_back(id);
    }
    queue<int> pending;
    vector<int> order;
    for (int letter = 0; letter < 26; letter++) {
        int next = trie[0].next[letter];
        if (next) pending.push(next);
    }
    while (!pending.empty()) {
        int vertex = pending.front();
        pending.pop();
        order.push_back(vertex);
        for (int letter = 0; letter < 26; letter++) {
            int next = trie[vertex].next[letter];
            if (next) {
                trie[next].link = trie[trie[vertex].link].next[letter];
                pending.push(next);
            } else trie[vertex].next[letter] = trie[trie[vertex].link].next[letter];
        }
    }
    string text;
    cin >> text;
    vector<int> found(patternCount);
    for (int vertex = 0; vertex < (int)trie.size(); vertex++)
        for (int id : trie[vertex].patterns) found[id]++;
    vector<int> visits(trie.size());
    int vertex = 0;
    for (char ch : text) { vertex = trie[vertex].next[ch - 'a']; visits[vertex]++; }
    reverse(order.begin(), order.end());
    for (int current : order) visits[trie[current].link] += visits[current];
    for (int i = 0; i < (int)trie.size(); i++)
        for (int id : trie[i].patterns) found[id] = visits[i];
    for (int count : found) cout << count << '\n';
    return 0;
}
