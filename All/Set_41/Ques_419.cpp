// Strongly Connected Components Kosaraju

#include <bits/stdc++.h>
using namespace std;

void dfsFirst(int vertex, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfsFirst(neighbor, graph, visited, st);
        }
    }
    st.push(vertex);
}

void dfsSecond(int vertex, vector<vector<int>>& reverseGraph, vector<bool>& visited, vector<int>& component) {
    visited[vertex] = true;
    component.push_back(vertex);
    for (int neighbor : reverseGraph[vertex]) {
        if (!visited[neighbor]) {
            dfsSecond(neighbor, reverseGraph, visited, component);
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> graph(vertices);
    vector<vector<int>> reverseGraph(vertices);

    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        reverseGraph[to].push_back(from);
    }

    vector<bool> visited(vertices, false);
    stack<int> st;

    for (int vertex = 0; vertex < vertices; ++vertex) {
        if (!visited[vertex]) {
            dfsFirst(vertex, graph, visited, st);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> components;

    while (!st.empty()) {
        int vertex = st.top();
        st.pop();
        if (!visited[vertex]) {
            vector<int> component;
            dfsSecond(vertex, reverseGraph, visited, component);
            components.push_back(component);
        }
    }

    for (const auto& comp : components) {
        for (int v : comp) {
            cout << v << ' ';
        }
        cout << '\n';
    }
    return 0;
}


