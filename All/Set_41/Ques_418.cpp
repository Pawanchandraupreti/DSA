// Centroid Decomposition

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> removed;
vector<int> subtreeSize;

int calculateSize(int vertex, int parent) {
    subtreeSize[vertex] = 1;
    for (int neighbor : graph[vertex]) {
        if (neighbor != parent && !removed[neighbor]) {
            subtreeSize[vertex] += calculateSize(neighbor, vertex);
        }
    }
    return subtreeSize[vertex];
}

int findCentroid(int vertex, int parent, int treeSize) {
    for (int neighbor : graph[vertex]) {
        if (neighbor != parent && !removed[neighbor] && subtreeSize[neighbor] > treeSize / 2) {
            return findCentroid(neighbor, vertex, treeSize);
        }
    }
    return vertex;
}

void decompose(int vertex) {
    int treeSize = calculateSize(vertex, -1);
    int centroid = findCentroid(vertex, -1, treeSize);
    removed[centroid] = true;

    for (int neighbor : graph[centroid]) {
        if (!removed[neighbor]) {
            decompose(neighbor);
        }
    }
}

int main() {
    int n;
    cin >> n;

    graph.resize(n);
    removed.resize(n, false);
    subtreeSize.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    decompose(0);
    cout << "Decomposition complete";
    return 0;
}
