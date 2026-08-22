// Dijkstra's Shortest Path from a Source

#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int vertices, const vector<vector<pair<int, int>>>& graph, int source) {
    const long long infinity = LLONG_MAX / 4;
    vector<long long> distances(vertices, infinity);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pending;

    distances[source] = 0;
    pending.push({0, source});

    while (!pending.empty()) {
        auto [currentDistance, vertex] = pending.top();
        pending.pop();

        if (currentDistance != distances[vertex]) {
            continue;
        }

        for (const auto& [neighbor, weight] : graph[vertex]) {
            long long newDistance = currentDistance + weight;
            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                pending.push({newDistance, neighbor});
            }
        }
    }

    return distances;
}

int main() {
    int vertices, edges, source;
    cin >> vertices >> edges >> source;

    vector<vector<pair<int, int>>> graph(vertices);
    for (int edge = 0; edge < edges; ++edge) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }

    vector<long long> distances = dijkstra(vertices, graph, source);
    for (long long distance : distances) {
        if (distance == LLONG_MAX / 4) {
            cout << -1 << ' ';
        } else {
            cout << distance << ' ';
        }
    }

    return 0;
}
