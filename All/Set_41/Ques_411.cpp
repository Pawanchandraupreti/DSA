// Articulation Points in Graph

#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& discoveryTime, vector<int>& lowTime, int& timer, int parent, set<int>& articulationPoints) {
    visited[vertex] = true;
    discoveryTime[vertex] = lowTime[vertex] = timer++;
    int children = 0;

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            children++;
            dfs(neighbor, graph, visited, discoveryTime, lowTime, timer, vertex, articulationPoints);
            lowTime[vertex] = min(lowTime[vertex], lowTime[neighbor]);

            if (parent == -1 && children > 1) {
                articulationPoints.insert(vertex);
            }
            if (parent != -1 && lowTime[neighbor] >= discoveryTime[vertex]) {
                articulationPoints.insert(vertex);
            }
        } else if (neighbor != parent) {
            lowTime[vertex] = min(lowTime[vertex], discoveryTime[neighbor]);
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

    vector<bool> visited(vertices, false);
    vector<int> discoveryTime(vertices, -1);
    vector<int> lowTime(vertices, -1);
    set<int> articulationPoints;
    int timer = 0;

    for (int vertex = 0; vertex < vertices; ++vertex) {
        if (!visited[vertex]) {
            dfs(vertex, graph, visited, discoveryTime, lowTime, timer, -1, articulationPoints);
        }
    }

    for (int point : articulationPoints) {
        cout << point << ' ';
    }
    return 0;
}
