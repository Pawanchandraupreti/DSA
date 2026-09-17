// Top K Frequent Elements

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    unordered_map<int, int> freq;
    for (int x : a) freq[x]++;

    vector<pair<int, int>> v(freq.begin(), freq.end());
    sort(v.begin(), v.end(), [](auto &p, auto &q) {
        return p.second > q.second;
    });

    for (int i = 0; i < min(k, (int)v.size()); i++) cout << v[i].first << ' ';
    cout << '\n';
    return 0;
}


