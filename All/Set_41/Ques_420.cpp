// Heavy Light Decomposition

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
int parent[MAXN], depth[MAXN], size[MAXN], heavy[MAXN], chain[MAXN], position[MAXN];
int chainCounter = 0;
int posCounter = 0;

void dfs(int vertex, int par) {
    parent[vertex] = par;
    size[vertex] = 1;
    heavy[vertex] = -1;
    for (int neighbor : graph[vertex]) {
        if (neighbor != par) {
            depth[neighbor] = depth[vertex] + 1;
            dfs(neighbor, vertex);
            size[vertex] += size[neighbor];
            if (heavy[vertex] == -1 || size[neighbor] > size[heavy[vertex]]) {
                heavy[vertex] = neighbor;
            }
        }
    }
}

void decompose(int vertex, int chainID) {
    chain[vertex] = chainID;
    position[vertex] = posCounter++;
    if (heavy[vertex] != -1) {
        decompose(heavy[vertex], chainID);
    }
    for (int neighbor : graph[vertex]) {
        if (neighbor != parent[vertex] && neighbor != heavy[vertex]) {
            decompose(neighbor, ++chainCounter);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    depth[0] = 0;
    dfs(0, -1);
    decompose(0, chainCounter++);

    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": chain=" << chain[i] << " pos=" << position[i] << '\n';
    }
    return 0;
}

