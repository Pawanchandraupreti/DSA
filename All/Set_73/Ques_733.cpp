// Reorganize String

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> frequency(26);
    for (char ch : s) frequency[ch - 'a']++;
    priority_queue<pair<int, char>> heap;
    for (int i = 0; i < 26; i++) if (frequency[i]) heap.push({frequency[i], char('a' + i)});

    string answer;
    pair<int, char> previous = {0, '#'};
    while (!heap.empty()) {
        auto current = heap.top();
        heap.pop();
        answer += current.second;
        if (previous.first) heap.push(previous);
        current.first--;
        previous = current;
    }
    cout << (answer.size() == s.size() ? answer : "") << '\n';
    return 0;
}
