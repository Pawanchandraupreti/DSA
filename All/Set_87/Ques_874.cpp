// Offline Dynamic Connectivity

#include <bits/stdc++.h>
using namespace std;

struct Query {
    char type;
    int u, v;
};

struct RollbackDsu {
    vector<int> parent, size;
    vector<pair<int, int>> changes;
    RollbackDsu(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int vertex) {
        while (parent[vertex] != vertex) vertex = parent[vertex];
        return vertex;
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) { changes.push_back({-1, -1}); return; }
        if (size[a] < size[b]) swap(a, b);
        changes.push_back({b, size[a]});
        parent[b] = a;
        size[a] += size[b];
    }
    int snapshot() { return changes.size(); }
    void rollback(int checkpoint) {
        while ((int)changes.size() > checkpoint) {
            auto [child, oldSize] = changes.back();
            changes.pop_back();
            if (child == -1) continue;
            size[parent[child]] = oldSize;
            parent[child] = child;
        }
    }
};

int main() {
    int n, queries;
    cin >> n >> queries;
    vector<Query> query(queries);
    map<pair<int, int>, int> started;
    vector<vector<pair<int, int>>> tree(4 * queries);
    auto add = [&](auto &&self, int node, int left, int right, int from, int to,
                   pair<int, int> edge) -> void {
        if (from >= right || to <= left) return;
        if (from <= left && right <= to) { tree[node].push_back(edge); return; }
        int middle = (left + right) / 2;
        self(self, node * 2, left, middle, from, to, edge);
        self(self, node * 2 + 1, middle, right, from, to, edge);
    };
    for (int i = 0; i < queries; i++) {
        cin >> query[i].type >> query[i].u >> query[i].v;
        if (query[i].u > query[i].v) swap(query[i].u, query[i].v);
        pair<int, int> edge = {query[i].u, query[i].v};
        if (query[i].type == '+') started[edge] = i;
        if (query[i].type == '-' && started.count(edge)) {
            add(add, 1, 0, queries, started[edge], i, edge);
            started.erase(edge);
        }
    }
    for (auto [edge, from] : started) add(add, 1, 0, queries, from, queries, edge);
    RollbackDsu dsu(n);
    function<void(int, int, int)> solve = [&](int node, int left, int right) {
        int checkpoint = dsu.snapshot();
        for (auto [u, v] : tree[node]) dsu.unite(u, v);
        if (right - left == 1) {
            if (query[left].type == '?') cout << (dsu.find(query[left].u) == dsu.find(query[left].v) ? "YES\n" : "NO\n");
        } else {
            int middle = (left + right) / 2;
            solve(node * 2, left, middle);
            solve(node * 2 + 1, middle, right);
        }
        dsu.rollback(checkpoint);
    };
    if (queries) solve(1, 0, queries);
    return 0;
}
