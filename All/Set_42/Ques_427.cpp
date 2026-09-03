// Euler Tour and Lowest Common Ancestor

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, queries;
    cin >> n >> queries;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int levels = 1;
    while ((1 << levels) <= n) ++levels;
    vector<vector<int>> ancestor(levels, vector<int>(n, 0));
    vector<int> depth(n);
    function<void(int, int)> dfs = [&](int vertex, int parent) {
        ancestor[0][vertex] = parent;
        for (int neighbor : graph[vertex]) {
            if (neighbor != parent) {
                depth[neighbor] = depth[vertex] + 1;
                dfs(neighbor, vertex);
            }
        }
    };
    dfs(0, 0);
    for (int level = 1; level < levels; ++level) {
        for (int vertex = 0; vertex < n; ++vertex) ancestor[level][vertex] = ancestor[level - 1][ancestor[level - 1][vertex]];
    }

    auto lca = [&](int first, int second) {
        if (depth[first] < depth[second]) swap(first, second);
        int difference = depth[first] - depth[second];
        for (int level = 0; level < levels; ++level) if (difference & (1 << level)) first = ancestor[level][first];
        if (first == second) return first;
        for (int level = levels - 1; level >= 0; --level) {
            if (ancestor[level][first] != ancestor[level][second]) {
                first = ancestor[level][first];
                second = ancestor[level][second];
            }
        }
        return ancestor[0][first];
    };

    while (queries--) {
        int first, second;
        cin >> first >> second;
        cout << lca(first, second) << '\n';
    }
    return 0;
}
