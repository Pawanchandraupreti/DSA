// Course Schedule Cycle Detection

#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>& g, vector<int>& state) {
    state[u] = 1;
    for (int v : g[u]) {
        if (state[v] == 1 || (!state[v] && dfs(v, g, state))) return true;
    }
    state[u] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
    }

    vector<int> state(n);
    for (int i = 0; i < n; i++) {
        if (!state[i] && dfs(i, g, state)) {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
    return 0;
}
