// Min-cost max-flow for assignment problem

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev, cap, cost;
};

struct MCMF {
    int n;
    vector<vector<Edge>> g;
    MCMF(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int cap, int cost) {
        Edge a{v, (int)g[v].size(), cap, cost};
        Edge b{u, (int)g[u].size(), 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }
    pair<int, int> minCostMaxFlow(int s, int t) {
        const int INF = 1e9;
        int flow = 0, cost = 0;
        vector<int> dist(n), pv(n), pe(n), inq(n);
        while (true) {
            fill(dist.begin(), dist.end(), INF);
            fill(inq.begin(), inq.end(), 0);
            queue<int> q;
            dist[s] = 0;
            q.push(s);
            inq[s] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop(); inq[u] = 0;
                for (int i = 0; i < (int)g[u].size(); ++i) {
                    Edge &e = g[u][i];
                    if (e.cap > 0 && dist[u] + e.cost < dist[e.to]) {
                        dist[e.to] = dist[u] + e.cost;
                        pv[e.to] = u;
                        pe[e.to] = i;
                        if (!inq[e.to]) q.push(e.to), inq[e.to] = 1;
                    }
                }
            }
            if (dist[t] == INF) break;
            int add = INF;
            for (int v = t; v != s; v = pv[v]) add = min(add, g[pv[v]][pe[v]].cap);
            flow += add;
            cost += add * dist[t];
            for (int v = t; v != s; v = pv[v]) {
                Edge &e = g[pv[v]][pe[v]];
                e.cap -= add;
                g[v][e.rev].cap += add;
            }
        }
        return {flow, cost};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];

    int S = 2 * n, T = 2 * n + 1;
    MCMF mf(2 * n + 2);
    for (int i = 0; i < n; ++i) mf.addEdge(S, i, 1, 0);
    for (int j = 0; j < n; ++j) mf.addEdge(n + j, T, 1, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mf.addEdge(i, n + j, 1, cost[i][j]);

    auto [flow, minCost] = mf.minCostMaxFlow(S, T);
    cout << flow << '\n' << minCost;
    return 0;
}

