// Alien Dictionary

#include <bits/stdc++.h>
using namespace std;

string alienOrder(const vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> indegree;

    for (const string& word : words) {
        for (char letter : word) {
            graph[letter];
            indegree[letter] = 0;
        }
    }

    for (int index = 0; index + 1 < (int)words.size(); ++index) {
        const string& first = words[index];
        const string& second = words[index + 1];
        int commonLength = min(first.size(), second.size());
        bool foundDifference = false;

        for (int position = 0; position < commonLength; ++position) {
            if (first[position] != second[position]) {
                if (!graph[first[position]].count(second[position])) {
                    graph[first[position]].insert(second[position]);
                    ++indegree[second[position]];
                }
                foundDifference = true;
                break;
            }
        }

        if (!foundDifference && first.size() > second.size()) {
            return "";
        }
    }

    queue<char> ready;
    for (const auto& [letter, degree] : indegree) {
        if (degree == 0) ready.push(letter);
    }

    string order;
    while (!ready.empty()) {
        char letter = ready.front();
        ready.pop();
        order.push_back(letter);

        for (char next : graph[letter]) {
            if (--indegree[next] == 0) ready.push(next);
        }
    }

    return order.size() == indegree.size() ? order : "";
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (string& word : words) cin >> word;

    string order = alienOrder(words);
    cout << (order.empty() ? "Invalid" : order);
    return 0;
}