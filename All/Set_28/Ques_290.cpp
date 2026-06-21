// Tarjan SCC: count components and largest size

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<int> disc(n + 1, 0), low(n + 1, 0), inStack(n + 1, 0), st;
    int timer = 0, sccCount = 0, largest = 0;

    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = ++timer;
        st.push_back(u);
        inStack[u] = 1;
        for (int v : g[u]) {
            if (!disc[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (low[u] == disc[u]) {
            ++sccCount;
            int sz = 0;
            while (true) {
                int v = st.back(); st.pop_back();
                inStack[v] = 0;
                ++sz;
                if (v == u) break;
            }
            largest = max(largest, sz);
        }
    };

    for (int i = 1; i <= n; ++i) if (!disc[i]) dfs(i);
    cout << sccCount << '\n' << largest;
    return 0;
}