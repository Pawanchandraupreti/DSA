// Diameter of a Tree

#include <bits/stdc++.h>
using namespace std;

pair<int, int> farthest(int s, const vector<vector<int>> &g) {
    vector<int> d(g.size(), -1);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    int last = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        last = u;
        for (int v : g[u]) if (d[v] == -1) {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    return {last, d[last]};
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << farthest(farthest(0, g).first, g).second << '\n';
    return 0;
}