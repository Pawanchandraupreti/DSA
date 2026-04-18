// Topological Sort (Kahn's Algorithm)
// Time Complexity: O(V + E)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topoSort(int n, vector<vector<int>>& g) {
    vector<int> indeg(n, 0);
    for(int u = 0; u < n; u++) {
        for(int v : g[u]) indeg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) q.push(i);
    }

    vector<int> order;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(int v : g[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    return order;
}

int main() {
    int n = 6;
    vector<vector<int>> g(n);

    g[5].push_back(2);
    g[5].push_back(0);
    g[4].push_back(0);
    g[4].push_back(1);
    g[2].push_back(3);
    g[3].push_back(1);

    vector<int> order = topoSort(n, g);
    for(int x : order) cout << x << " ";
}
