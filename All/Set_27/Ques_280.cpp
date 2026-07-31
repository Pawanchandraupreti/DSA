// Eulerian path in directed graph (Hierholzer)

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        g[u].push_back(v);
        outdeg[u]++;
        indeg[v]++;
    }

    int start = -1;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (outdeg[i] - indeg[i] == 1) {
            s1++;
        } else if (indeg[i] - outdeg[i] == 1) {
            s2++;
        } else if (indeg[i] != outdeg[i]) {
            cout << -1;
            return 0;
        }

        if (outdeg[i] > 0 && start == -1) start = i;
    }

    if (!((s1 == 1 && s2 == 1) || (s1 == 0 && s2 == 0))) {
        cout << -1;
        return 0;
    }

    if (start == -1) start = 1;

    vector<int> idx(n + 1, 0), st, path;
    st.push_back(start);

    while (!st.empty()) {
        int v = st.back();
        if (idx[v] < (int)g[v].size()) {
            st.push_back(g[v][idx[v]++]);
        } else {
            path.push_back(v);
            st.pop_back();
        }
    }

    if ((int)path.size() != m + 1) {
        cout << -1;
        return 0;
    }

    reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }

    return 0;
}
