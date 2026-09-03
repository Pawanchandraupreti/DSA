// Bridges in an Undirected Graph

#include <bits/stdc++.h>
using namespace std;

void findBridges(int vertex, int parent, vector<vector<int>>& graph, vector<int>& discovery, vector<int>& low, int& timer, vector<pair<int, int>>& bridges) {
    discovery[vertex] = low[vertex] = timer++;
    for (int neighbor : graph[vertex]) {
        if (neighbor == parent) continue;
        if (discovery[neighbor] == -1) {
            findBridges(neighbor, vertex, graph, discovery, low, timer, bridges);
            low[vertex] = min(low[vertex], low[neighbor]);
            if (low[neighbor] > discovery[vertex]) bridges.push_back({min(vertex, neighbor), max(vertex, neighbor)});
        } else {
            low[vertex] = min(low[vertex], discovery[neighbor]);
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> graph(vertices);
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> discovery(vertices, -1), low(vertices);
    vector<pair<int, int>> bridges;
    int timer = 0;
    for (int vertex = 0; vertex < vertices; ++vertex) {
        if (discovery[vertex] == -1) findBridges(vertex, -1, graph, discovery, low, timer, bridges);
    }
    sort(bridges.begin(), bridges.end());
    for (auto [from, to] : bridges) cout << from << ' ' << to << '\n';
    return 0;
}
