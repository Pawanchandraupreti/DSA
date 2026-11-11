// Heavy-Light Decomposition for Maximum Path Queries

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, queries;
    cin >> n >> queries;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> value(n), parent(n), depth(n), subtree(n), heavy(n, -1);
    for (int &x : value) cin >> x;
    function<void(int)> prepare = [&](int vertex) {
        subtree[vertex] = 1;
        for (int next : graph[vertex]) if (next != parent[vertex]) {
            parent[next] = vertex; depth[next] = depth[vertex] + 1;
            prepare(next);
            subtree[vertex] += subtree[next];
            if (heavy[vertex] == -1 || subtree[next] > subtree[heavy[vertex]]) heavy[vertex] = next;
        }
    };
    prepare(0);
    vector<int> head(n), position(n), base;
    int timer = 0;
    function<void(int, int)> decompose = [&](int vertex, int chain) {
        head[vertex] = chain; position[vertex] = timer++;
        base.push_back(value[vertex]);
        if (heavy[vertex] != -1) decompose(heavy[vertex], chain);
        for (int next : graph[vertex]) if (next != parent[vertex] && next != heavy[vertex]) decompose(next, next);
    };
    decompose(0, 0);
    int size = 1;
    while (size < n) size <<= 1;
    vector<int> segment(2 * size, INT_MIN);
    for (int i = 0; i < n; i++) segment[size + i] = base[i];
    for (int i = size - 1; i; i--) segment[i] = max(segment[2 * i], segment[2 * i + 1]);
    auto rangeMax = [&](int left, int right) {
        int answer = INT_MIN;
        for (left += size, right += size + 1; left < right; left >>= 1, right >>= 1) {
            if (left & 1) answer = max(answer, segment[left++]);
            if (right & 1) answer = max(answer, segment[--right]);
        }
        return answer;
    };
    while (queries--) {
        int u, v;
        cin >> u >> v;
        int answer = INT_MIN;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            answer = max(answer, rangeMax(position[head[u]], position[u]));
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        cout << max(answer, rangeMax(position[u], position[v])) << '\n';
    }
    return 0;
}
