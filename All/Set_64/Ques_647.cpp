// Top K Frequent Elements

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> frequency;
    for (int &x : a) {
        cin >> x;
        frequency[x]++;
    }

    vector<pair<int, int>> values;
    for (auto [value, count] : frequency) values.push_back({count, value});
    sort(values.rbegin(), values.rend());
    for (int i = 0; i < k && i < (int)values.size(); i++) cout << values[i].second << ' ';
    cout << '\n';
    return 0;
}

