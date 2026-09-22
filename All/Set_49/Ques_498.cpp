// Top K Frequent Words

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<string, int> freq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        freq[s]++;
    }

    vector<pair<int, string>> items;
    for (auto &p : freq) items.push_back({p.second, p.first});
    sort(items.begin(), items.end(), [](auto &a, auto &b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    for (int i = 0; i < k; i++) cout << items[i].second << ' ';
    cout << '\n';
    return 0;
}