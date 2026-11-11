// Maximum Flow in a Directed Network

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, capacity, reverse;
};

int main() {
    int vertices, edges, source, sink;
    cin >> vertices >> edges >> source >> sink;
    vector<vector<Edge>> graph(vertices);
    auto addEdge = [&](int from, int to, int capacity) {
        graph[from].push_back({to, capacity, (int)graph[to].size()});
        graph[to].push_back({from, 0, (int)graph[from].size() - 1});
    };
    for (int i = 0; i < edges; i++) {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        addEdge(from, to, capacity);
    }
    long long answer = 0;
    while (true) {
        vector<int> level(vertices, -1), current(vertices);
        queue<int> pending;
        pending.push(source);
        level[source] = 0;
        while (!pending.empty()) {
            int vertex = pending.front();
            pending.pop();
            for (const Edge &edge : graph[vertex]) {
                if (edge.capacity && level[edge.to] == -1) {
                    level[edge.to] = level[vertex] + 1;
                    pending.push(edge.to);
                }
            }
        }
        if (level[sink] == -1) break;
        function<int(int, int)> send = [&](int vertex, int flow) {
            if (vertex == sink) return flow;
            while (current[vertex] < (int)graph[vertex].size()) {
                Edge &edge = graph[vertex][current[vertex]];
                if (edge.capacity && level[edge.to] == level[vertex] + 1) {
                    int pushed = send(edge.to, min(flow, edge.capacity));
                    if (pushed) {
                        edge.capacity -= pushed;
                        graph[edge.to][edge.reverse].capacity += pushed;
                        return pushed;
                    }
                }
                current[vertex]++;
            }
            return 0;
        };
        while (int pushed = send(source, INT_MAX)) answer += pushed;
    }
    cout << answer << '\n';
    return 0;
}
