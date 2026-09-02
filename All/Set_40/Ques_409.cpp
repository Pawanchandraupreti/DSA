// Maximum Flow Ford-Fulkerson

#include <bits/stdc++.h>
using namespace std;

int dfs(int vertex, int sink, vector<vector<int>>& capacity, vector<vector<int>>& graph, vector<bool>& visited, int minCapacity) {
    if (vertex == sink) return minCapacity;

    visited[vertex] = true;
    for (int next : graph[vertex]) {
        if (!visited[next] && capacity[vertex][next] > 0) {
            int flow = dfs(next, sink, capacity, graph, visited, min(minCapacity, capacity[vertex][next]));
            if (flow > 0) {
                capacity[vertex][next] -= flow;
                capacity[next][vertex] += flow;
                return flow;
            }
        }
    }
    return 0;
}

int maxFlow(int source, int sink, vector<vector<int>>& capacity, vector<vector<int>>& graph, int vertices) {
    int totalFlow = 0;

    while (true) {
        vector<bool> visited(vertices, false);
        int flow = dfs(source, sink, capacity, graph, visited, INT_MAX);
        if (flow == 0) break;
        totalFlow += flow;
    }

    return totalFlow;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> capacity(vertices, vector<int>(vertices, 0));
    vector<vector<int>> graph(vertices);

    for (int edge = 0; edge < edges; ++edge) {
        int from, to, flowCapacity;
        cin >> from >> to >> flowCapacity;
        capacity[from][to] += flowCapacity;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int source, sink;
    cin >> source >> sink;

    cout << maxFlow(source, sink, capacity, graph, vertices);
    return 0;
}