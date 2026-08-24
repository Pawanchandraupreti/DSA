// Strongly Connected Components using Kosaraju's Algorithm

#include <bits/stdc++.h>
using namespace std;

void fillOrder(int vertex, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& order) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) fillOrder(neighbor, graph, visited, order);
    }
    order.push(vertex);
}

void collectComponent(int vertex, const vector<vector<int>>& reversedGraph, vector<bool>& visited, vector<int>& component) {
    visited[vertex] = true;
    component.push_back(vertex);
    for (int neighbor : reversedGraph[vertex]) {
        if (!visited[neighbor]) collectComponent(neighbor, reversedGraph, visited, component);
    }
}

vector<vector<int>> stronglyConnectedComponents(int vertices, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(vertices), reversedGraph(vertices);
    for (auto [from, to] : edges) {
        graph[from].push_back(to);
        reversedGraph[to].push_back(from);
    }

    vector<bool> visited(vertices, false);
    stack<int> order;
    for (int vertex = 0; vertex < vertices; ++vertex) {
        if (!visited[vertex]) fillOrder(vertex, graph, visited, order);
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> components;
    while (!order.empty()) {
        int vertex = order.top();
        order.pop();
        if (!visited[vertex]) {
            vector<int> component;
            collectComponent(vertex, reversedGraph, visited, component);
            sort(component.begin(), component.end());
            components.push_back(component);
        }
    }

    sort(components.begin(), components.end());
    return components;
}

int main() {
    int vertices, edgesCount;
    cin >> vertices >> edgesCount;

    vector<pair<int, int>> edges(edgesCount);
    for (auto& [from, to] : edges) cin >> from >> to;

    for (const auto& component : stronglyConnectedComponents(vertices, edges)) {
        for (int vertex : component) cout << vertex << ' ';
        cout << '\n';
    }
    return 0;
}
