// Maximum bipartite matching using Hopcroft-Karp

#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp {
    int n, m;
    vector<vector<int>> g;
    vector<int> dist, matchL, matchR;

    HopcroftKarp(int n, int m) : n(n), m(m), g(n + 1), dist(n + 1), matchL(n + 1, 0), matchR(m + 1, 0) {}

    void addEdge(int u, int v) { g[u].push_back(v); }

    bool bfs() {
        queue<int> q;
        bool found = false;
        for (int i = 1; i <= n; ++i) {
            if (!matchL[i]) dist[i] = 0, q.push(i);
            else dist[i] = -1;
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                int nxt = matchR[v];
                if (!nxt) found = true;
                else if (dist[nxt] == -1) {
                    dist[nxt] = dist[u] + 1;
                    q.push(nxt);
                }
            }
        }
        return found;
    }

    bool dfs(int u) {
        for (int v : g[u]) {
            int nxt = matchR[v];
            if (!nxt || (dist[nxt] == dist[u] + 1 && dfs(nxt))) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int maxMatching() {
        int ans = 0;
        while (bfs()) {
            for (int i = 1; i <= n; ++i) if (!matchL[i] && dfs(i)) ++ans;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, e;
    if (!(cin >> n >> m >> e)) return 0;
    HopcroftKarp hk(n, m);
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        hk.addEdge(u, v);
    }
    cout << hk.maxMatching();
    return 0;
}

