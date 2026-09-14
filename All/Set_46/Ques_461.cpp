// Merge K Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> a(k);

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        a[i].resize(n);
        for (int& x : a[i]) cin >> x;
        if (n) pq.push({a[i][0], {i, 0}});
    }

    while (!pq.empty()) {
        auto [x, pos] = pq.top();
        pq.pop();
        auto [r, c] = pos;
        cout << x << ' ';
        if (c + 1 < (int)a[r].size()) pq.push({a[r][c + 1], {r, c + 1}});
    }
    return 0;
}
