// Minimum Cost Maximum Flow

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, reverse, capacity, cost;
};

void addEdge(vector<vector<Edge>>& graph, int from, int to, int capacity, int cost) {
    graph[from].push_back({to, (int)graph[to].size(), capacity, cost});
    graph[to].push_back({from, (int)graph[from].size() - 1, 0, -cost});
}

pair<int, long long> minCostMaxFlow(vector<vector<Edge>>& graph, int source, int sink) {
    int vertices = (int)graph.size();
    int totalFlow = 0;
    long long totalCost = 0;

    while (true) {
        vector<long long> distance(vertices, LLONG_MAX);
        vector<int> parentVertex(vertices, -1), parentEdge(vertices, -1);
        vector<bool> inQueue(vertices, false);
        queue<int> pending;
        distance[source] = 0;
        pending.push(source);
        inQueue[source] = true;

        while (!pending.empty()) {
            int vertex = pending.front();
            pending.pop();
            inQueue[vertex] = false;
            for (int index = 0; index < (int)graph[vertex].size(); ++index) {
                Edge& edge = graph[vertex][index];
                if (edge.capacity > 0 && distance[edge.to] > distance[vertex] + edge.cost) {
                    distance[edge.to] = distance[vertex] + edge.cost;
                    parentVertex[edge.to] = vertex;
                    parentEdge[edge.to] = index;
                    if (!inQueue[edge.to]) {
                        pending.push(edge.to);
                        inQueue[edge.to] = true;
                    }
                }
            }
        }

        if (distance[sink] == LLONG_MAX) break;
        int flow = INT_MAX;
        for (int vertex = sink; vertex != source; vertex = parentVertex[vertex]) {
            flow = min(flow, graph[parentVertex[vertex]][parentEdge[vertex]].capacity);
        }
        for (int vertex = sink; vertex != source; vertex = parentVertex[vertex]) {
            Edge& edge = graph[parentVertex[vertex]][parentEdge[vertex]];
            edge.capacity -= flow;
            graph[vertex][edge.reverse].capacity += flow;
        }
        totalFlow += flow;
        totalCost += 1LL * flow * distance[sink];
    }
    return {totalFlow, totalCost};
}

int main() {
    int vertices, edges, source, sink;
    cin >> vertices >> edges >> source >> sink;
    vector<vector<Edge>> graph(vertices);
    for (int i = 0; i < edges; ++i) {
        int from, to, capacity, cost;
        cin >> from >> to >> capacity >> cost;
        addEdge(graph, from, to, capacity, cost);
    }
    auto [flow, cost] = minCostMaxFlow(graph, source, sink);
    cout << flow << ' ' << cost;
    return 0;
}
