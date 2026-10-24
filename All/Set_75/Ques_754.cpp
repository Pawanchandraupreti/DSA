// Sort Characters by Frequency

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> frequency;
    for (char ch : s) frequency[ch]++;
    vector<pair<int, char>> values;
    for (auto [ch, count] : frequency) values.push_back({count, ch});
    sort(values.rbegin(), values.rend());
    for (auto [count, ch] : values) cout << string(count, ch);
    cout << '\n';
    return 0;
}
