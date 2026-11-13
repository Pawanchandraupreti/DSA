// Dynamic Nearest Marked Vertex

#include <bits/stdc++.h>
using namespace std;

struct CentroidTree {
    vector<vector<int>> graph;
    vector<int> blocked, subtree;
    vector<vector<pair<int, int>>> paths;
    vector<int> best;
    CentroidTree(int n) : graph(n), blocked(n), subtree(n), paths(n), best(n, INT_MAX) {}
    int getSize(int vertex, int parent) {
        subtree[vertex] = 1;
        for (int next : graph[vertex]) if (next != parent && !blocked[next])
            subtree[vertex] += getSize(next, vertex);
        return subtree[vertex];
    }
    int getCentroid(int vertex, int parent, int total) {
        for (int next : graph[vertex])
            if (next != parent && !blocked[next] && subtree[next] > total / 2)
                return getCentroid(next, vertex, total);
        return vertex;
    }
    void collect(int vertex, int parent, int distance, int centroid) {
        paths[vertex].push_back({centroid, distance});
        for (int next : graph[vertex])
            if (next != parent && !blocked[next]) collect(next, vertex, distance + 1, centroid);
    }
    void build(int entry) {
        int centroid = getCentroid(entry, -1, getSize(entry, -1));
        blocked[centroid] = 1;
        collect(centroid, -1, 0, centroid);
        for (int next : graph[centroid]) if (!blocked[next]) build(next);
    }
};

int main() {
    int n, queries;
    cin >> n >> queries;
    CentroidTree tree(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree.graph[u].push_back(v);
        tree.graph[v].push_back(u);
    }
    tree.build(0);
    while (queries--) {
        int type, vertex;
        cin >> type >> vertex;
        if (type == 1) {
            for (auto [centroid, distance] : tree.paths[vertex])
                tree.best[centroid] = min(tree.best[centroid], distance);
        } else {
            int answer = INT_MAX;
            for (auto [centroid, distance] : tree.paths[vertex])
                answer = min(answer, distance + tree.best[centroid]);
            cout << answer << '\n';
        }
    }
    return 0;
}
