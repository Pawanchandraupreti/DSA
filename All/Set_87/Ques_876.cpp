// Minimum Cost Maximum Flow

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, capacity, cost, reverse;
};

int main() {
    int n, m, source, sink;
    cin >> n >> m >> source >> sink;
    vector<vector<Edge>> graph(n);
    auto addEdge = [&](int from, int to, int capacity, int cost) {
        graph[from].push_back({to, capacity, cost, (int)graph[to].size()});
        graph[to].push_back({from, 0, -cost, (int)graph[from].size() - 1});
    };
    for (int i = 0; i < m; i++) {
        int u, v, capacity, cost;
        cin >> u >> v >> capacity >> cost;
        addEdge(u, v, capacity, cost);
    }
    long long totalCost = 0;
    int totalFlow = 0;
    while (true) {
        const int infinity = 1e9;
        vector<int> distance(n, infinity), previousVertex(n), previousEdge(n);
        vector<bool> inQueue(n);
        queue<int> pending;
        distance[source] = 0; pending.push(source); inQueue[source] = true;
        while (!pending.empty()) {
            int vertex = pending.front();
            pending.pop(); inQueue[vertex] = false;
            for (int i = 0; i < (int)graph[vertex].size(); i++) {
                Edge &edge = graph[vertex][i];
                if (edge.capacity && distance[edge.to] > distance[vertex] + edge.cost) {
                    distance[edge.to] = distance[vertex] + edge.cost;
                    previousVertex[edge.to] = vertex; previousEdge[edge.to] = i;
                    if (!inQueue[edge.to]) { inQueue[edge.to] = true; pending.push(edge.to); }
                }
            }
        }
        if (distance[sink] == infinity) break;
        int pushed = INT_MAX;
        for (int vertex = sink; vertex != source; vertex = previousVertex[vertex])
            pushed = min(pushed, graph[previousVertex[vertex]][previousEdge[vertex]].capacity);
        for (int vertex = sink; vertex != source; vertex = previousVertex[vertex]) {
            Edge &edge = graph[previousVertex[vertex]][previousEdge[vertex]];
            edge.capacity -= pushed;
            graph[vertex][edge.reverse].capacity += pushed;
        }
        totalFlow += pushed;
        totalCost += 1LL * pushed * distance[sink];
    }
    cout << totalFlow << ' ' << totalCost << '\n';
    return 0;
}
